/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_multicast_adapter.o -> add_multicast_listener_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void add_multicast_listener_task(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  esp_openthread_get_netif();
  uVar1 = to_underlying_lwip_netif();
  iVar2 = esp_openthread_multicast_listener_add(param_1,&uStack_24,uVar1);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Failed to add OpenThread multicast listener\n",uVar1);
  }
  free(param_1);
  return;
}

