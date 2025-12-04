/*
 * Last changed at upstream commit 66e81acb8df80dbc52a2b0841a8ae3153557e131
 * https://github.com/espressif/esp-thread-lib/commit/66e81acb8df80dbc52a2b0841a8ae3153557e131
 * Upstream date: 2025-12-04 07:38:20 +0000
 * Upstream subject: fix(openthread): resolve deadlock issues due to switching_lock
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_multicast_router_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  esp_openthread_get_backbone_netif();
  uVar2 = to_underlying_lwip_netif();
  esp_openthread_get_netif();
  uVar3 = to_underlying_lwip_netif();
  iVar1 = 0x103;
  if (s_multicast_router_initialized == '\0') {
    iVar1 = find_or_create_netif_listener_list(uVar2);
    if (iVar1 != 0) {
      iVar1 = find_or_create_netif_listener_list(uVar3);
      if (iVar1 != 0) {
        esp_openthread_task_switching_lock_release();
        iVar1 = esp_netif_tcpip_exec(multicast_router_init_on_lwip_task,0);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        if (iVar1 != 0) {
          return iVar1;
        }
        esp_openthread_get_instance();
        otBackboneRouterSetMulticastListenerCallback
                  (&esp_openthread_handle_thread_multicast_listener,0);
        esp_openthread_get_instance();
        iVar1 = otBackboneRouterGetState();
        if (iVar1 == 2) {
          esp_openthread_multicast_forwarding_set_enabled(1);
        }
        s_multicast_router_initialized = 1;
        return 0;
      }
      free_all_netif_listener_list();
    }
    iVar1 = 0x101;
  }
  return iVar1;
}

