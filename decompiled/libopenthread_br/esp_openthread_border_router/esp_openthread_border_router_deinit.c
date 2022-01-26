/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_deinit(void)

{
  esp_openthread_srp_server_deinit();
  esp_openthread_discovery_delegate_deinit();
  esp_openthread_multicast_router_deinit();
  esp_openthread_infra_if_deinit();
  return;
}

