/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> UpdateFdSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::UpdateFdSet(esp_openthread_mainloop_context_t*) */

void __thiscall Resolver::UpdateFdSet(Resolver *this,esp_openthread_mainloop_context_t *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  esp_openthread_mainloop_context_t *peVar5;
  int iVar6;
  
  iVar6 = *(int *)(this + 4);
  for (iVar2 = 0; iVar6 != iVar2; iVar2 = iVar2 + 1) {
    piVar4 = (int *)(*(int *)this + iVar2 * 8);
    if (*piVar4 != 0) {
      uVar3 = piVar4[1];
      if (uVar3 < 0x40) {
        peVar5 = param_1 + ((int)uVar3 >> 5) * 4;
        uVar1 = 1 << (uVar3 & 0x1f);
        *(uint *)peVar5 = *(uint *)peVar5 | uVar1;
        *(uint *)(peVar5 + 0x10) = *(uint *)(peVar5 + 0x10) | uVar1;
      }
      if (*(int *)(param_1 + 0x18) < (int)uVar3) {
        *(uint *)(param_1 + 0x18) = uVar3;
      }
    }
  }
  return;
}

