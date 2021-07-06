/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_netif_glue_process(int param_1)

{
  undefined4 uVar1;
  
  if ((int)DAT_00010b4c < 0) {
    return 0;
  }
  if (DAT_00010b4c < 0x40) {
    if ((1 << (DAT_00010b4c & 0x1f) & *(uint *)(param_1 + (DAT_00010b4c >> 5) * 4)) == 0) {
      return 0;
    }
    uVar1 = process_thread_transmit();
    return uVar1;
  }
  return 0;
}

