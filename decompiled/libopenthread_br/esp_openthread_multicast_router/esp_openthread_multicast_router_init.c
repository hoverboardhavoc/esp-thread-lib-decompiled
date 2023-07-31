/*
 * Last changed at upstream commit 6d739fee07d4758fc2fa200b1d3edec99663a930
 * https://github.com/espressif/esp-thread-lib/commit/6d739fee07d4758fc2fa200b1d3edec99663a930
 * Upstream date: 2023-07-31 15:11:37 +0800
 * Upstream subject: feat(br): Fix memory leak and setting mcast forwarding enable
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
  iVar3 = 0x103;
  if (s_netif_listener_lists == 0) {
    iVar3 = find_or_create_netif_listener_list(uVar1);
    if (iVar3 != 0) {
      iVar3 = find_or_create_netif_listener_list(uVar2);
      if (iVar3 != 0) {
        iStack_18 = 0;
        uStack_14 = xTaskGetCurrentTaskHandle();
        esp_openthread_task_switching_lock_release();
        tcpip_callback(multicast_router_init_on_lwip_task,&iStack_18);
        ulTaskGenericNotifyTake(0,1,0xffffffff);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        if (iStack_18 != 0) {
          return iStack_18;
        }
        esp_openthread_get_instance();
        otBackboneRouterSetMulticastListenerCallback
                  (&esp_openthread_handle_thread_multicast_listener,0);
        esp_openthread_get_instance();
        iVar3 = otBackboneRouterGetState();
        if (iVar3 != 2) {
          return iStack_18;
        }
        esp_openthread_multicast_forwarding_set_enabled(1);
        return iStack_18;
      }
      free_all_netif_listener_list();
    }
    iVar3 = 0x101;
  }
  return iVar3;
}

