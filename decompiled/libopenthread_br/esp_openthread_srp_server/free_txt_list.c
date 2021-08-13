/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> free_txt_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_txt_list(void *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvVar3;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    puVar1 = (undefined4 *)(uVar2 * 8 + (int)param_1);
    pvVar3 = (void *)*puVar1;
    if (pvVar3 != (void *)0x0) {
      free(pvVar3);
    }
    pvVar3 = (void *)puVar1[1];
    if (pvVar3 != (void *)0x0) {
      free(pvVar3);
    }
  }
  free(param_1);
  return;
}

