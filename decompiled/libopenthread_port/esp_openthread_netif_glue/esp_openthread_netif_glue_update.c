/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_update(int param_1)

{
  uint *puVar1;
  
  if (-1 < (int)DAT_00010b4c) {
    if (DAT_00010b4c < 0x40) {
      puVar1 = (uint *)((DAT_00010b4c >> 5) * 4 + param_1);
      *puVar1 = *puVar1 | 1 << (DAT_00010b4c & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)DAT_00010b4c) {
      *(uint *)(param_1 + 0x18) = DAT_00010b4c;
    }
  }
  return;
}

