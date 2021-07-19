/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> free_txt_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_txt_list(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvVar3;
  
  if (param_1 == 0) {
    return;
  }
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    puVar1 = (undefined4 *)(uVar2 * 8 + param_1);
    pvVar3 = (void *)*puVar1;
    if (pvVar3 != (void *)0x0) {
      free(pvVar3);
    }
    pvVar3 = (void *)puVar1[1];
    if (pvVar3 != (void *)0x0) {
      free(pvVar3);
    }
  }
  return;
}

