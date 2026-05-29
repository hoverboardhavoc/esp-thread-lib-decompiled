# -*- coding: utf-8 -*-
# Ghidra postScript (Jython 2.7): decompile every function in the current
# program to per-function .c files under $DECOMP_OUT. The outer process.sh
# adds the file header -- we write only the raw decompile body here.
#
# Jython is bundled with Ghidra and is loaded by a non-OSGi ScriptProvider,
# so this script avoids the osgi.ee=UNKNOWN BundleException that affects
# the Java/JavaScriptProvider path under JDK 21.
#@category Decompile
#@runtime Jython

import os
import re

from ghidra.app.decompiler import DecompInterface, DecompileOptions

SAFE_RE = re.compile(r'[^A-Za-z0-9_.-]')


def main():
    out_dir = os.environ.get("DECOMP_OUT")
    if not out_dir:
        println("DECOMP_OUT env var not set; aborting")
        return
    if not os.path.isdir(out_dir):
        try:
            os.makedirs(out_dir)
        except OSError as e:
            println("Could not create %s: %s" % (out_dir, e))
            return

    decomp = DecompInterface()
    opts = DecompileOptions()
    decomp.setOptions(opts)
    decomp.toggleCCode(True)
    decomp.toggleSyntaxTree(True)
    decomp.setSimplificationStyle("decompile")

    try:
        if not decomp.openProgram(currentProgram):
            println("openProgram failed: " + str(decomp.getLastMessage()))
            return

        name_counts = {}
        funcs = currentProgram.getFunctionManager().getFunctions(True)
        written = 0
        for fn in funcs:
            if monitor.isCancelled():
                break
            if fn.isExternal() or fn.isThunk():
                continue
            raw = fn.getName()
            safe = SAFE_RE.sub('_', raw)
            if not safe:
                safe = "fn_%x" % fn.getEntryPoint().getOffset()
            n = name_counts.get(safe, 0)
            name_counts[safe] = n + 1
            fname = safe if n == 0 else "%s__%d" % (safe, n)

            try:
                res = decomp.decompileFunction(fn, 60, monitor)
                if res is None or not res.decompileCompleted():
                    msg = "null" if res is None else res.getErrorMessage()
                    println("decompile failed: %s - %s" % (raw, msg))
                    continue
                c = res.getDecompiledFunction().getC()
                if c is None:
                    continue
                out_path = os.path.join(out_dir, fname + ".c")
                f = open(out_path, "w")
                try:
                    f.write(c)
                finally:
                    f.close()
                written += 1
            except Exception as e:
                println("exception on %s: %s" % (raw, e))

        println("DecompileDump: wrote %d files to %s" % (written, out_dir))
    finally:
        decomp.dispose()


main()
