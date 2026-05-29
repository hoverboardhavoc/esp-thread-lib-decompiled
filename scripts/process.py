#!/usr/bin/env python3
"""Auto-decompile pipeline for esp-thread-lib-decompiled.

For each unprocessed upstream commit that touched a target archive
(oldest first, bounded by MAX_COMMITS_PER_RUN), this script:

  1. globs esp32c3/*.a against the upstream checkout to discover the
     blob archive(s) at that commit,
  2. extracts each archive's .o members with ``ar x``,
  3. detects each archive's processor from an .o member via ``readelf -h``
     (RISC-V -> RISCV:LE:32:default; Xtensa / no bundled Ghidra module ->
     the archive is skipped and logged),
  4. runs Ghidra headless on each .o, dumping per-function .c via
     scripts/DecompileDump.py (a Jython postScript -- it bypasses Ghidra's
     OSGi-based Java compilation path, which fails under JDK 21 with
     osgi.ee=UNKNOWN),
  5. for each function, compares the new decompiled body to the existing
     file (header stripped). If the body is identical the existing file is
     left untouched (its header keeps pointing at the older upstream commit
     where the body last actually changed). Otherwise the file is rewritten
     with a new header naming THIS commit,
  6. removes files for functions no longer present,
  7. commits + pushes one commit per upstream commit onto the orphan
     ``decompiled`` branch (never master), authored and committed by
     ``blobmaster`` with the upstream commit's date.

Stdlib only (Python 3). Run as ``python3 scripts/process.py`` from anywhere;
the repo root is derived from this file's location.

Environment:
  GHIDRA_HOME          required -- Ghidra install root (has support/analyzeHeadless)
  UPSTREAM_DIR         optional -- upstream working clone (default /tmp/upstream)
  MAX_COMMITS_PER_RUN  optional -- per-run commit cap (default 3)
  WALL_CLOCK_BUDGET_SECONDS  optional -- stop starting commits past this many
                                   seconds of wall-clock (default 18000 ~5h;
                                   0 disables) to stay under GitHub's 6h cap
  GHIDRA_PROCESSOR     optional -- force the Ghidra processor for every blob
                                   (overrides per-blob readelf detection)
"""

import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

# --- target configuration (rendered from @@-tokens) -------------------------
UPSTREAM_REPO = "espressif/esp-thread-lib"
UPSTREAM_URL = "https://github.com/espressif/esp-thread-lib.git"
TARGET_GLOB = "esp32c3/*.a"
OUTPUT_DIR = "decompiled"
COPYRIGHT_HOLDER = "Espressif"
# Upstream license (detected from the upstream repo at scaffold time), used in
# the per-file header. Vendor-agnostic: reflects the upstream's actual license.
UPSTREAM_LICENSE = "Apache License 2.0"
# Orphan branch carrying the decompiled source. Every commit this script makes
# lands here; the fork's ``master`` (the upstream mirror) is never touched.
BRANCH = "decompiled"

# --- fixed pipeline identity (never templated) ------------------------------
COMMITTER_NAME = "blobmaster"
COMMITTER_EMAIL = "blobmaster.crux120@passmail.net"
RISCV_PROCESSOR = "RISCV:LE:32:default"

REPO_ROOT = Path(__file__).resolve().parent.parent
UPSTREAM_DIR = Path(os.environ.get("UPSTREAM_DIR", "/tmp/upstream"))
MAX_COMMITS_PER_RUN = int(os.environ.get("MAX_COMMITS_PER_RUN", "3"))
# Belt-and-suspenders alongside MAX_COMMITS_PER_RUN: stop *starting* a new
# commit once this many seconds of wall-clock have elapsed, so a heavy batch
# bows out gracefully (surfacing the backlog + CATCHUP.md, exit 0) well before
# GitHub's hard 6h (21600s) per-job kill, which would abort mid-commit. 0
# disables the guard. Default ~5h leaves headroom for the in-flight commit.
WALL_CLOCK_BUDGET_SECONDS = int(os.environ.get("WALL_CLOCK_BUDGET_SECONDS", "18000"))
GHIDRA_PROCESSOR_OVERRIDE = os.environ.get("GHIDRA_PROCESSOR", "").strip()

GHIDRA_HOME = os.environ.get("GHIDRA_HOME")
if not GHIDRA_HOME:
    sys.stderr.write("[process.py] GHIDRA_HOME must be set\n")
    sys.exit(2)
ANALYZE_HEADLESS = Path(GHIDRA_HOME) / "support" / "analyzeHeadless"


def log(msg):
    sys.stderr.write("[process.py] %s\n" % msg)
    sys.stderr.flush()


def run(cmd, cwd=None, env=None, check=True, capture=False):
    """Thin subprocess wrapper. Returns stdout text when capture=True."""
    kwargs = {"cwd": str(cwd) if cwd else None, "env": env}
    if capture:
        kwargs["stdout"] = subprocess.PIPE
        kwargs["stderr"] = subprocess.STDOUT
    res = subprocess.run([str(c) for c in cmd], **kwargs)
    if check and res.returncode != 0:
        raise subprocess.CalledProcessError(res.returncode, cmd)
    if capture:
        return res.stdout.decode("utf-8", "replace")
    return res.returncode


def git(args, cwd, **kw):
    return run(["git", "-C", str(cwd)] + list(args), **kw)


def git_out(args, cwd):
    return git(args, cwd, capture=True).strip()


def strip_header(path):
    """Drop our leading ``/* ... */`` header (lines 1..first ' */')."""
    lines = Path(path).read_text(encoding="utf-8", errors="replace").splitlines(keepends=True)
    if not lines or lines[0].rstrip("\n") != "/*":
        return "".join(lines)
    out, in_h = [], True
    for i, line in enumerate(lines):
        if i == 0:
            continue
        if in_h:
            if line.rstrip("\n") == " */":
                in_h = False
            continue
        out.append(line)
    return "".join(out)


def detect_processor(o_file):
    """Map an ELF .o to a bundled Ghidra processor via ``readelf -h``.

    Returns the processor id (str) or None when no bundled module applies
    (e.g. Xtensa), in which case the caller should skip the archive.
    """
    if GHIDRA_PROCESSOR_OVERRIDE:
        return GHIDRA_PROCESSOR_OVERRIDE
    try:
        out = run(["readelf", "-h", str(o_file)], capture=True, check=False)
    except FileNotFoundError:
        log("    readelf not found; cannot detect arch")
        return None
    machine = ""
    for line in out.splitlines():
        if "Machine:" in line:
            machine = line.split("Machine:", 1)[1].strip()
            break
    if "RISC-V" in machine:
        return RISCV_PROCESSOR
    log("    arch '%s' has no bundled Ghidra processor -- skipping" % (machine or "unknown"))
    return None


def sync_to_remote():
    """Defensive reset to the true remote branch tip (guards a checkout race).

    Operates only on the decompiled BRANCH; master (the upstream mirror) is
    never fetched or reset here.
    """
    if (REPO_ROOT / ".git").is_dir():
        log("syncing local %s to origin/%s (defensive against checkout race)"
            % (BRANCH, BRANCH))
        git(["fetch", "--quiet", "origin", BRANCH], REPO_ROOT, check=False)
        git(["reset", "--hard", "origin/%s" % BRANCH], REPO_ROOT, check=False)


def update_upstream():
    if (UPSTREAM_DIR / ".git").is_dir():
        log("fetching upstream")
        git(["fetch", "--quiet", "origin"], UPSTREAM_DIR)
        try:
            ref = git_out(["symbolic-ref", "--short", "refs/remotes/origin/HEAD"], UPSTREAM_DIR)
        except subprocess.CalledProcessError:
            ref = "origin/master"
        git(["checkout", "-q", ref.replace("refs/remotes/", "")], UPSTREAM_DIR)
    else:
        log("cloning upstream %s -> %s" % (UPSTREAM_URL, UPSTREAM_DIR))
        UPSTREAM_DIR.parent.mkdir(parents=True, exist_ok=True)
        run(["git", "clone", "--quiet", UPSTREAM_URL, str(UPSTREAM_DIR)])


def upstream_commits():
    """Commits touching the target glob, oldest first."""
    out = git_out(["log", "--reverse", "--pretty=format:%H", "--", TARGET_GLOB], UPSTREAM_DIR)
    return [s for s in out.splitlines() if s]


def find_blobs():
    """Glob the target archive(s) under the current upstream checkout."""
    return sorted(p for p in UPSTREAM_DIR.glob(TARGET_GLOB) if p.is_file())


def member_base(name):
    """Object-member filename -> clean stem.

    ESP archives name members either `foo.o` (legacy) or `foo.c.obj` (built
    through the IDF). Strip the object suffix and any trailing `.c` so both
    styles yield the same `foo` directory name -- otherwise IDF members leave
    a per-member output directory literally named `foo.c`, which the `*.c`
    glob in sync_outputs would wrongly pick up as a source file.
    """
    for suffix in (".obj", ".o"):
        if name.endswith(suffix):
            name = name[:-len(suffix)]
            break
    if name.endswith(".c"):
        name = name[:-len(".c")]
    return name


def ghidra_decompile(o_file, processor, scratch, out_dir):
    """Run analyzeHeadless on one .o, dumping per-function .c into out_dir."""
    out_dir.mkdir(parents=True, exist_ok=True)
    proj = scratch / "proj"
    proj.mkdir(parents=True, exist_ok=True)
    log_path = scratch / ("ghidra_%s.log" % o_file.stem)
    env = dict(os.environ)
    env["DECOMP_OUT"] = str(out_dir)
    cmd = [
        ANALYZE_HEADLESS, str(proj), "p_%s" % o_file.stem,
        "-import", str(o_file),
        "-loader", "ElfLoader",
        "-processor", processor,
        "-scriptPath", str(REPO_ROOT / "scripts"),
        "-postScript", "DecompileDump.py",
        "-deleteProject",
    ]
    with open(log_path, "wb") as lf:
        rc = subprocess.run([str(c) for c in cmd], stdout=lf, stderr=subprocess.STDOUT, env=env).returncode
    if rc != 0:
        log("  WARN ghidra non-zero on %s" % o_file.stem)
    produced = list(out_dir.rglob("*.c"))
    log("    -> %d .c files produced" % len(produced))
    if not produced:
        tail = log_path.read_text("utf-8", "replace").splitlines()[-40:]
        log("    ---- ghidra log for %s (last 40 lines) ----" % o_file.stem)
        for line in tail:
            sys.stderr.write("    | %s\n" % line)
        log("    -------------------------------------------")
    return len(produced)


def decompile_commit(sha, scratch, new_root):
    """Decompile every RISC-V blob present at ``sha`` into ``new_root``.

    Returns (riscv_blobs, total_c_files): riscv_blobs counts archives that
    had a bundled processor (so 0 .c from a >0 riscv_blobs run is a fault),
    total_c_files is the .c count across all members.
    """
    riscv_blobs = 0
    total_c = 0
    for blob in find_blobs():
        rel = blob.relative_to(UPSTREAM_DIR)
        members_dir = scratch / "members" / blob.stem
        members_dir.mkdir(parents=True, exist_ok=True)
        run(["ar", "x", str(blob)], cwd=members_dir)
        # ESP archives use either `.o` or, when built through the IDF, `*.c.obj`.
        members = sorted(p for p in members_dir.iterdir()
                         if p.is_file() and p.suffix in (".o", ".obj"))
        if not members:
            log("  %s: no object members" % rel)
            continue
        processor = detect_processor(members[0])
        if processor is None:
            log("  %s: skipped (no bundled Ghidra processor)" % rel)
            continue
        riscv_blobs += 1
        log("  %s: %d members, processor %s" % (rel, len(members), processor))
        for o in members:
            base = member_base(o.name)
            log("  ghidra: %s/%s" % (blob.stem, base))
            # new_root/<archive-stem>/<member>/<function>.c
            out_dir = new_root / blob.stem / base
            total_c += ghidra_decompile(o, processor, scratch, out_dir)
    return riscv_blobs, total_c


def write_header(sha, date_iso, subject, rel_source):
    return "".join([
        "/*\n",
        " * Last changed at upstream commit %s\n" % sha,
        " * https://github.com/%s/commit/%s\n" % (UPSTREAM_REPO, sha),
        " * Upstream date: %s\n" % date_iso,
        " * Upstream subject: %s\n" % subject,
        " * Source: %s\n" % rel_source,
        " *\n",
        " * (C) %s, %s.\n" % (COPYRIGHT_HOLDER, UPSTREAM_LICENSE),
        " * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).\n",
        " * Decompiler output may be incomplete or differ from original semantics.\n",
        " */\n",
    ])


def sync_outputs(sha, date_iso, subject, new_root, output_root):
    """Write/update changed files; remove files with no new counterpart."""
    new_files = sorted(p for p in new_root.rglob("*.c") if p.is_file())
    for newfile in new_files:
        rel = newfile.relative_to(new_root)
        existing = output_root / rel
        new_body = newfile.read_text("utf-8", "replace")
        if existing.is_file() and strip_header(existing) == new_body:
            continue
        existing.parent.mkdir(parents=True, exist_ok=True)
        # rel == <archive-stem>/<member>/<function>.c
        parts = rel.parts
        source = "%s -> %s.o -> %s" % (
            parts[0] if parts else rel.name,
            parts[1] if len(parts) > 1 else "?",
            newfile.stem,
        )
        existing.write_text(write_header(sha, date_iso, subject, source) + new_body,
                            encoding="utf-8")
    # prune files whose function no longer exists in the new decompile
    if output_root.is_dir():
        for existing in sorted(p for p in output_root.rglob("*.c") if p.is_file()):
            rel = existing.relative_to(output_root)
            if not (new_root / rel).is_file():
                existing.unlink()


def commit_and_push(sha, date_iso, date_short, subject, n_blobs, output_dir):
    env = dict(os.environ)
    env.update({
        "GIT_AUTHOR_NAME": COMMITTER_NAME,
        "GIT_AUTHOR_EMAIL": COMMITTER_EMAIL,
        "GIT_AUTHOR_DATE": date_iso,
        "GIT_COMMITTER_NAME": COMMITTER_NAME,
        "GIT_COMMITTER_EMAIL": COMMITTER_EMAIL,
        "GIT_COMMITTER_DATE": date_iso,
    })
    git(["add", "-A", "processed", output_dir], REPO_ROOT)
    staged_clean = git(["diff", "--cached", "--quiet", "--", output_dir],
                       REPO_ROOT, check=False) == 0
    if staged_clean:
        summary = "no functional changes since previous"
    else:
        changed = git_out(["diff", "--cached", "--name-only", "--", output_dir], REPO_ROOT)
        summary = "%d files changed" % len([x for x in changed.splitlines() if x])
    git(["commit",
         "-m", "decompile: upstream %s (%s) -- %s" % (sha, date_short, summary),
         "-m", "Upstream commit: https://github.com/%s/commit/%s" % (UPSTREAM_REPO, sha),
         "-m", "Upstream subject: %s" % subject,
         "-m", "Archives decompiled: %d" % n_blobs],
        REPO_ROOT, env=env)
    # Push only the decompiled branch; master is never written.
    git(["push", "origin", "HEAD:%s" % BRANCH], REPO_ROOT)


def report_backlog(commits):
    """Compare processed markers against the upstream glob-HEAD.

    ``commits`` is the oldest-first list of every upstream commit touching the
    target glob, so ``commits[-1]`` is the upstream-glob-HEAD (the newest such
    commit). A target is only caught up when EVERY one of those commits has a
    ``processed/<sha>.done`` marker -- i.e. the latest processed upstream SHA
    equals the upstream-glob-HEAD.

    Returns (n, m, k, glob_head, last_processed): n = processed count, m =
    total upstream glob-commits, k = remaining (m - n). K==0 means caught up;
    K>0 means drain-pending (a manual re-dispatch is needed). This is the
    authoritative "done" criterion: never treat a single dispatch that left
    K>0 as success.
    """
    processed_dir = REPO_ROOT / "processed"
    remaining = [s for s in commits
                 if not (processed_dir / ("%s.done" % s)).is_file()]
    total = len(commits)
    k = len(remaining)
    n = total - k
    glob_head = commits[-1] if commits else None
    last_processed = None
    for s in reversed(commits):
        if (processed_dir / ("%s.done" % s)).is_file():
            last_processed = s
            break
    if k == 0:
        log("CAUGHT UP: processed %d/%d upstream glob-commits; decompiled "
            "branch is at upstream-glob-HEAD %s" % (total, total, glob_head))
    else:
        log("DRAIN-PENDING: processed %d/%d upstream glob-commits; %d "
            "remaining. Latest processed=%s, upstream-glob-HEAD=%s. Re-dispatch "
            "the workflow (Run workflow / `gh workflow run process.yml --ref "
            "%s`) to continue draining." % (n, total, k, last_processed,
                                            glob_head, BRANCH))
    return n, total, k, glob_head, last_processed


def _catchup_lines(n, m, k, glob_head, last_processed):
    """Human-readable backlog lines shared by the step summary and CATCHUP.md."""
    state = ("CAUGHT UP" if k == 0
             else "Batch OK -- DRAIN-PENDING (re-run to continue)")
    lines = [
        "# Decompile catch-up status",
        "",
        "- **Status:** %s" % state,
        "- **Processed:** %d / %d upstream glob-commits" % (n, m),
        "- **Remaining:** %d" % k,
        "- **Upstream-glob-HEAD:** `%s`" % (glob_head or "(none)"),
        "- **Latest processed:** `%s`" % (last_processed or "(none)"),
        "",
    ]
    if k == 0:
        lines.append("The `%s` branch is caught up to the upstream glob-HEAD; "
                     "no re-dispatch needed." % BRANCH)
    else:
        lines.append("%d upstream glob-commit(s) remain undecompiled. Re-dispatch "
                     "the workflow (**Run workflow** in the Actions tab, or "
                     "`gh workflow run process.yml --ref %s`) and repeat until "
                     "**0 commits remaining**." % (k, BRANCH))
    lines.append("")
    return "\n".join(lines)


def write_step_summary(n, m, k, glob_head, last_processed):
    """Append the backlog to $GITHUB_STEP_SUMMARY (no-op when unset, e.g. local)."""
    path = os.environ.get("GITHUB_STEP_SUMMARY")
    if not path:
        log("GITHUB_STEP_SUMMARY unset; skipping step-summary (local run)")
        return
    with open(path, "a", encoding="utf-8") as fh:
        fh.write(_catchup_lines(n, m, k, glob_head, last_processed))
        fh.write("\n")
    log("Wrote backlog to $GITHUB_STEP_SUMMARY")


def commit_catchup(n, m, k, glob_head, last_processed):
    """Write CATCHUP.md and commit it on BRANCH (skip when content unchanged).

    Dated to the latest processed upstream commit (or the glob-HEAD when
    nothing has been processed yet) so the commit's date stays monotonic with
    the per-commit decompile commits already on the branch. master is never
    touched.
    """
    catchup = REPO_ROOT / "CATCHUP.md"
    catchup.write_text(_catchup_lines(n, m, k, glob_head, last_processed),
                       encoding="utf-8")
    git(["add", "CATCHUP.md"], REPO_ROOT)
    if git(["diff", "--cached", "--quiet", "--", "CATCHUP.md"],
           REPO_ROOT, check=False) == 0:
        log("CATCHUP.md unchanged; no commit")
        return
    date_sha = last_processed or glob_head
    if date_sha is None:
        log("No upstream glob-commits; skipping CATCHUP.md commit")
        return
    date_iso = git_out(["show", "-s", "--format=%ci", date_sha], UPSTREAM_DIR)
    env = dict(os.environ)
    env.update({
        "GIT_AUTHOR_NAME": COMMITTER_NAME,
        "GIT_AUTHOR_EMAIL": COMMITTER_EMAIL,
        "GIT_AUTHOR_DATE": date_iso,
        "GIT_COMMITTER_NAME": COMMITTER_NAME,
        "GIT_COMMITTER_EMAIL": COMMITTER_EMAIL,
        "GIT_COMMITTER_DATE": date_iso,
    })
    state = "caught up" if k == 0 else "%d remaining" % k
    git(["commit", "-m",
         "blobmill: catch-up status -- processed %d/%d (%s)" % (n, m, state)],
        REPO_ROOT, env=env)
    git(["push", "origin", "HEAD:%s" % BRANCH], REPO_ROOT)
    log("Committed + pushed CATCHUP.md")


def main():
    (REPO_ROOT / "processed").mkdir(parents=True, exist_ok=True)
    (REPO_ROOT / OUTPUT_DIR).mkdir(parents=True, exist_ok=True)

    sync_to_remote()
    update_upstream()

    commits = upstream_commits()
    log("%d upstream commits touch %s" % (len(commits), TARGET_GLOB))

    scratch_base = Path("/tmp/blobmill_scratch")
    output_root = REPO_ROOT / OUTPUT_DIR

    processed_count = 0
    run_start = time.monotonic()
    for sha in commits:
        if processed_count >= MAX_COMMITS_PER_RUN:
            log("Reached MAX_COMMITS_PER_RUN=%d, stopping" % MAX_COMMITS_PER_RUN)
            break
        if WALL_CLOCK_BUDGET_SECONDS > 0:
            elapsed = time.monotonic() - run_start
            if elapsed >= WALL_CLOCK_BUDGET_SECONDS:
                log("Wall-clock budget reached (%.0fs >= %ds); stopping before "
                    "the next commit to stay under GitHub's 6h job cap"
                    % (elapsed, WALL_CLOCK_BUDGET_SECONDS))
                break
        done_file = REPO_ROOT / "processed" / ("%s.done" % sha)
        if done_file.is_file():
            continue

        log("Processing upstream %s" % sha)
        date_iso = git_out(["show", "-s", "--format=%ci", sha], UPSTREAM_DIR)
        date_short = date_iso.split(" ", 1)[0]
        subject = git_out(["show", "-s", "--format=%s", sha], UPSTREAM_DIR)
        git(["checkout", "-q", sha], UPSTREAM_DIR)

        if not find_blobs():
            log("No target archive at %s; marking processed (no-op)" % sha)
            done_file.write_text("")
            commit_and_push(sha, date_iso, date_short,
                            subject + " [target absent]", 0, OUTPUT_DIR)
            processed_count += 1
            continue

        if scratch_base.exists():
            shutil.rmtree(scratch_base)
        scratch = scratch_base
        new_root = scratch / "new_decomp"
        new_root.mkdir(parents=True, exist_ok=True)

        riscv_blobs, total_c = decompile_commit(sha, scratch, new_root)
        log("RISC-V archives: %d; total .c files: %d" % (riscv_blobs, total_c))

        if riscv_blobs == 0:
            # All blobs at this commit are Xtensa / unbundled -> expected skip,
            # not a fault. Record a no-op commit so we don't reprocess it.
            log("No RISC-V archives at %s; marking processed (skip)" % sha)
            done_file.write_text("")
            commit_and_push(sha, date_iso, date_short,
                            subject + " [no decompilable arch]", 0, OUTPUT_DIR)
            processed_count += 1
            continue

        if total_c == 0:
            # RISC-V blobs were present but Ghidra emitted nothing -> fault.
            log("ERROR: Ghidra produced 0 .c for upstream %s despite RISC-V "
                "archives -- refusing to push an empty commit. Aborting so a "
                "future run can diagnose (see /tmp ghidra logs)." % sha)
            sys.exit(1)

        sync_outputs(sha, date_iso, subject, new_root, output_root)
        done_file.write_text("")
        commit_and_push(sha, date_iso, date_short, subject, riscv_blobs, OUTPUT_DIR)
        processed_count += 1

    log("Done. Processed %d commits this run." % processed_count)

    # Authoritative done-criterion: compare against the upstream-glob-HEAD,
    # recorded in CATCHUP.md / the step summary (NOT this run's exit code).
    # A partial batch is a *successful* batch with more work queued, so it
    # exits 0 (green) -- this keeps non-zero reserved for GENUINE faults
    # (0 .c on RISC-V, push rejection, unexpected exception) so a real
    # problem never hides behind a sea of red "still draining" runs. The
    # re-dispatch decision is made by reading CATCHUP.md's K, never by this
    # exit status.
    n, m, backlog, glob_head, last_processed = report_backlog(commits)
    write_step_summary(n, m, backlog, glob_head, last_processed)
    commit_catchup(n, m, backlog, glob_head, last_processed)
    if backlog > 0:
        log("Batch OK -- processed %d/%d upstream glob-commits, %d remaining "
            "(re-run to continue draining). Exiting 0 (drain-pending is a "
            "successful partial batch; see CATCHUP.md for K)."
            % (n, m, backlog))
        sys.exit(0)
    log("CAUGHT UP: processed %d/%d upstream glob-commits, 0 remaining. "
        "Exiting 0." % (n, m))


if __name__ == "__main__":
    main()
