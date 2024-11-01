/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_multicast_adapter.o -> remove_multicast_listener_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void remove_multicast_listener_task(void *param_1)

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
  iVar2 = esp_openthread_multicast_listener_remove(param_1,&uStack_24,uVar1);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,"E (%lu) %s: Failed to remove OpenThread multicast listener\n",uVar1,
                  0x10000);
  }
  free(param_1);
  return;
}

