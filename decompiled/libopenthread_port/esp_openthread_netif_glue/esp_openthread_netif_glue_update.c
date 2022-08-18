/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_update(int param_1)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = DAT_000112a8;
  if (-1 < (int)DAT_000112a8) {
    if ((int)DAT_000112a8 < 0x40) {
      puVar2 = (uint *)(((int)DAT_000112a8 >> 5) * 4 + param_1);
      *puVar2 = *puVar2 | 1 << (DAT_000112a8 & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

