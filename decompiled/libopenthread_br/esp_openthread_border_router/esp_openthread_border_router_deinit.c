/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_deinit(void)

{
  esp_openthread_route_table_clear();
  esp_openthread_srp_server_deinit();
  esp_openthread_discovery_delegate_deinit();
  esp_openthread_remove_meshcop_mdns();
  esp_openthread_multicast_router_deinit();
  esp_openthread_get_instance();
  otRemoveStateChangeCallback(esp_openthread_border_router_state_callback,0);
  nat64_remove_all_sessions();
  esp_border_router_turn_off_nat64_netif();
  esp_openthread_infra_if_deinit();
  return;
}

