/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> process_finished_host
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* process_finished_host(pending_query_t*, mdns_search_once_s*, mdns_result_s*) */

void process_finished_host
               (pending_query_t *param_1,mdns_search_once_s *param_2,mdns_result_s *param_3)

{
  append_to_query_result(param_1,param_3);
  esp_openthread_get_instance();
  otDnssdQueryHandleDiscoveredHost(param_1 + 0x100,param_1 + 0x300);
  free_addresses_in_pending_query(param_1);
  return;
}

