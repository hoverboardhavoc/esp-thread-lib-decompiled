/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> dns_upstream_resolver_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dns_upstream_resolver_update(esp_openthread_mainloop_context_t*) */

void dns_upstream_resolver_update(esp_openthread_mainloop_context_t *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  esp_openthread_mainloop_context_t *peVar5;
  int iVar6;
  
  if (g_resolver == (int *)0x0) {
    return;
  }
  iVar6 = g_resolver[1];
  piVar3 = (int *)*g_resolver;
  for (iVar1 = 0; iVar6 != iVar1; iVar1 = iVar1 + 1) {
    if (*piVar3 != 0) {
      uVar4 = piVar3[1];
      if (uVar4 < 0x40) {
        peVar5 = param_1 + ((int)uVar4 >> 5) * 4;
        uVar2 = 1 << (uVar4 & 0x1f);
        *(uint *)peVar5 = *(uint *)peVar5 | uVar2;
        *(uint *)(peVar5 + 0x10) = *(uint *)(peVar5 + 0x10) | uVar2;
      }
      if (*(int *)(param_1 + 0x18) < (int)uVar4) {
        *(uint *)(param_1 + 0x18) = uVar4;
      }
    }
    piVar3 = piVar3 + 2;
  }
  return;
}

