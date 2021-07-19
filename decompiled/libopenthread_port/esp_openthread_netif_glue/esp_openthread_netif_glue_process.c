/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_netif_glue_process(int param_1)

{
  undefined4 uVar1;
  
  if ((int)DAT_00010afc < 0) {
    return 0;
  }
  if (DAT_00010afc < 0x40) {
    if ((1 << (DAT_00010afc & 0x1f) & *(uint *)(param_1 + (DAT_00010afc >> 5) * 4)) == 0) {
      return 0;
    }
    uVar1 = process_thread_transmit();
    return uVar1;
  }
  return 0;
}

