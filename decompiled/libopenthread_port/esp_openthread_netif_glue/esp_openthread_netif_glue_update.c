/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
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
  
  uVar1 = DAT_00011290;
  if (-1 < (int)DAT_00011290) {
    if ((int)DAT_00011290 < 0x40) {
      puVar2 = (uint *)(((int)DAT_00011290 >> 5) * 4 + param_1);
      *puVar2 = *puVar2 | 1 << (DAT_00011290 & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

