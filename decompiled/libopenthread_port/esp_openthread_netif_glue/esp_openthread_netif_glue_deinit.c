/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_deinit(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_openthread_get_instance();
  otIp6SetAddressCallback(0,0);
  otIp6SetReceiveCallback(uVar1,0,0);
  if (s_packet_queue != 0) {
    vQueueDelete();
    s_packet_queue = 0;
  }
  if (-1 < DAT_000112a8) {
    close(DAT_000112a8);
    DAT_000112a8 = -1;
  }
  iVar2 = esp_event_post(OPENTHREAD_EVENT,1,0,0,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC28,uVar1,"OPENTHREAD");
  }
  s_openthread_netif = 0;
  esp_event_handler_unregister(OPENTHREAD_EVENT,0,&esp_netif_action_start);
  esp_event_handler_unregister(OPENTHREAD_EVENT,1,&esp_netif_action_stop);
  esp_event_handler_unregister(OPENTHREAD_EVENT,2,&esp_netif_action_connected);
  esp_event_handler_unregister(OPENTHREAD_EVENT,3,&esp_netif_action_disconnected);
  esp_event_handler_unregister(OPENTHREAD_EVENT,4,&esp_netif_action_add_ip6_address);
  esp_event_handler_unregister(OPENTHREAD_EVENT,5,&esp_netif_action_remove_ip6_address);
  esp_event_handler_unregister(OPENTHREAD_EVENT,6,&esp_netif_action_join_ip6_multicast_group);
  esp_event_handler_unregister(OPENTHREAD_EVENT,7,&esp_netif_action_leave_ip6_multicast_group);
  esp_openthread_platform_workflow_unregister("netif_glue");
  return;
}

