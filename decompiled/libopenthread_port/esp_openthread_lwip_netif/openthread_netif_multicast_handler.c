/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_lwip_netif.o -> openthread_netif_multicast_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 openthread_netif_multicast_handler(void *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_20 [24];
  
  memcpy(auStack_20,param_1,0x10);
  esp_openthread_task_switching_lock_acquire();
  if (param_2 == 1) {
    esp_openthread_get_instance();
    uVar1 = otIp6SubscribeMulticastAddress(auStack_20);
  }
  else {
    esp_openthread_get_instance();
    uVar1 = otIp6UnsubscribeMulticastAddress(auStack_20);
  }
  esp_openthread_task_switching_lock_release();
  uVar2 = 0xfffffff0;
  if (uVar1 != 7) {
    if (uVar1 < 8) {
      uVar2 = 0;
      if ((uVar1 != 0) && (uVar2 = 0xfffffff4, uVar1 == 3)) {
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = 0xfffffff4;
      if (uVar1 == 0x18) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

