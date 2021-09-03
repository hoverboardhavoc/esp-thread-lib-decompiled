/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> esp_openthread_discovery_delegate_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_discovery_delegate_deinit(void)

{
  close(s_mdns_event_fd);
  s_mdns_event_fd = 0xffffffff;
  vQueueDelete(s_mdns_result_queue);
  s_mdns_result_queue = 0;
  esp_openthread_get_instance();
  otDnssdQuerySetCallbacks(0,0,0);
  esp_openthread_platform_workflow_unregister("discovery");
  return;
}

