/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> Process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::Process(esp_openthread_mainloop_context_t const*) */

void __thiscall Resolver::Process(Resolver *this,esp_openthread_mainloop_context_t *param_1)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar1 = 0; uVar1 < *(uint *)(this + 4); uVar1 = uVar1 + 1) {
    piVar2 = (int *)(*(int *)this + uVar1 * 8);
    if ((*piVar2 != 0) && (uVar3 = piVar2[1], uVar3 < 0x40)) {
      uVar4 = 1 << (uVar3 & 0x1f);
      if (((*(uint *)(param_1 + ((int)uVar3 >> 5) * 4 + 0x10) & uVar4) != 0) ||
         ((uVar4 & *(uint *)(param_1 + ((int)uVar3 >> 5) * 4)) != 0)) {
        ForwardResponse((Transaction *)this);
        FindAndCloseTransaction(this,*(otPlatDnsUpstreamQuery **)(*(int *)this + uVar1 * 8));
      }
    }
  }
  return;
}

