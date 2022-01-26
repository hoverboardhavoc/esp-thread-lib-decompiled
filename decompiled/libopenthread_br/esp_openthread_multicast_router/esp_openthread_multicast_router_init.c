/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_multicast_router_init(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iStack_18;
  undefined4 uStack_14;
  
  esp_openthread_get_backbone_netif();
  uVar1 = to_underlying_lwip_netif();
  esp_openthread_get_netif();
  uVar2 = to_underlying_lwip_netif();
  iStack_18 = 0x103;
  if (s_netif_listener_lists == 0) {
    iVar3 = find_or_create_netif_listener_list(uVar1);
    iStack_18 = 0x101;
    if (iVar3 != 0) {
      iVar3 = find_or_create_netif_listener_list(uVar2);
      if (iVar3 == 0) {
        free_all_netif_listener_list();
        iStack_18 = 0x101;
      }
      else {
        iStack_18 = 0;
        uStack_14 = xTaskGetCurrentTaskHandle();
        esp_openthread_lock_release();
        tcpip_callback(multicast_router_init_on_lwip_task,&iStack_18);
        ulTaskGenericNotifyTake(0,1,0xffffffff);
        esp_openthread_lock_acquire(0xffffffff);
        if (iStack_18 == 0) {
          esp_openthread_get_instance();
          otBackboneRouterSetMulticastListenerCallback
                    (&esp_openthread_handle_thread_multicast_listener,0);
        }
      }
    }
  }
  return iStack_18;
}

