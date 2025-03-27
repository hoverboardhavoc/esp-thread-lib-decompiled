/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> dns_upstream_resolver_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dns_upstream_resolver_update(esp_openthread_mainloop_context_t*) */

void dns_upstream_resolver_update(esp_openthread_mainloop_context_t *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  esp_openthread_mainloop_context_t *peVar6;
  int iVar7;
  
  piVar1 = g_resolver;
  if (g_resolver == (int *)0x0) {
    return;
  }
  iVar7 = g_resolver[1];
  for (iVar3 = 0; iVar7 != iVar3; iVar3 = iVar3 + 1) {
    piVar5 = (int *)(*piVar1 + iVar3 * 8);
    if (*piVar5 != 0) {
      uVar4 = piVar5[1];
      if (uVar4 < 0x40) {
        peVar6 = param_1 + ((int)uVar4 >> 5) * 4;
        uVar2 = 1 << (uVar4 & 0x1f);
        *(uint *)peVar6 = *(uint *)peVar6 | uVar2;
        *(uint *)(peVar6 + 0x10) = *(uint *)(peVar6 + 0x10) | uVar2;
      }
      if (*(int *)(param_1 + 0x18) < (int)uVar4) {
        *(uint *)(param_1 + 0x18) = uVar4;
      }
    }
  }
  return;
}

