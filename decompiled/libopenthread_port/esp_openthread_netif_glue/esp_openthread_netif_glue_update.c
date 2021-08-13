/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_update(int param_1)

{
  uint *puVar1;
  
  if (-1 < (int)DAT_00010b80) {
    if (DAT_00010b80 < 0x40) {
      puVar1 = (uint *)((DAT_00010b80 >> 5) * 4 + param_1);
      *puVar1 = *puVar1 | 1 << (DAT_00010b80 & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)DAT_00010b80) {
      *(uint *)(param_1 + 0x18) = DAT_00010b80;
    }
  }
  return;
}

