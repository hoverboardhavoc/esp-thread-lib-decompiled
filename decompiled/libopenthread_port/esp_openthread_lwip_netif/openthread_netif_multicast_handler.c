/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
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
  esp_openthread_lock_acquire(0xffffffff);
  if (param_2 == 1) {
    esp_openthread_get_instance();
    uVar1 = otIp6SubscribeMulticastAddress(auStack_20);
  }
  else {
    esp_openthread_get_instance();
    uVar1 = otIp6UnsubscribeMulticastAddress(auStack_20);
  }
  esp_openthread_lock_release();
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

