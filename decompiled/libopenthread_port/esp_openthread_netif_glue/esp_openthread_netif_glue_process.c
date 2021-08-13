/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_netif_glue_process(int param_1)

{
  undefined4 uVar1;
  
  if ((int)DAT_00010b80 < 0) {
    return 0;
  }
  if (DAT_00010b80 < 0x40) {
    if ((1 << (DAT_00010b80 & 0x1f) & *(uint *)(param_1 + (DAT_00010b80 >> 5) * 4)) == 0) {
      return 0;
    }
    uVar1 = process_thread_transmit();
    return uVar1;
  }
  return 0;
}

