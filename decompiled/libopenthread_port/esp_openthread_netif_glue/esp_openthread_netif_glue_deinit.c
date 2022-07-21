/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
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
  if (-1 < DAT_00011290) {
    close(DAT_00011290);
    DAT_00011290 = -1;
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

