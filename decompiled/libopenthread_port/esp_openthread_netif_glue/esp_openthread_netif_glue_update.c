/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_update(int param_1)

{
  uint *puVar1;
  
  if (-1 < (int)DAT_00010afc) {
    if (DAT_00010afc < 0x40) {
      puVar1 = (uint *)((DAT_00010afc >> 5) * 4 + param_1);
      *puVar1 = *puVar1 | 1 << (DAT_00010afc & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)DAT_00010afc) {
      *(uint *)(param_1 + 0x18) = DAT_00010afc;
    }
  }
  return;
}

