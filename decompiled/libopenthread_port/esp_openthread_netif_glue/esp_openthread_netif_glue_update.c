/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_update(int param_1)

{
  uint *puVar1;
  
  if (-1 < (int)DAT_00010c98) {
    if (DAT_00010c98 < 0x40) {
      puVar1 = (uint *)((DAT_00010c98 >> 5) * 4 + param_1);
      *puVar1 = *puVar1 | 1 << (DAT_00010c98 & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)DAT_00010c98) {
      *(uint *)(param_1 + 0x18) = DAT_00010c98;
    }
  }
  return;
}

