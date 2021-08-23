/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_netif_glue_process(int param_1)

{
  undefined4 uVar1;
  
  if ((int)DAT_00010c98 < 0) {
    return 0;
  }
  if (DAT_00010c98 < 0x40) {
    if ((1 << (DAT_00010c98 & 0x1f) & *(uint *)(param_1 + (DAT_00010c98 >> 5) * 4)) == 0) {
      return 0;
    }
    uVar1 = process_thread_transmit();
    return uVar1;
  }
  return 0;
}

