/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> unregister_openthread_event_handlers
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void unregister_openthread_event_handlers(void)

{
  esp_event_handler_unregister(OPENTHREAD_EVENT,0,&esp_netif_action_start);
  esp_event_handler_unregister(OPENTHREAD_EVENT,1,&esp_netif_action_stop);
  esp_event_handler_unregister(OPENTHREAD_EVENT,2,&esp_netif_action_connected);
  esp_event_handler_unregister(OPENTHREAD_EVENT,3,&esp_netif_action_disconnected);
  esp_event_handler_unregister(OPENTHREAD_EVENT,4,&esp_netif_action_add_ip6_address);
  esp_event_handler_unregister(OPENTHREAD_EVENT,5,&esp_netif_action_remove_ip6_address);
  esp_event_handler_unregister(OPENTHREAD_EVENT,6,&esp_netif_action_join_ip6_multicast_group);
  esp_event_handler_unregister(OPENTHREAD_EVENT,7,&esp_netif_action_leave_ip6_multicast_group);
  return;
}

