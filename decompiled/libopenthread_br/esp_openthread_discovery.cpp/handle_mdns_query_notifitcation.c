/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> handle_mdns_query_notifitcation
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* handle_mdns_query_notifitcation(mdns_search_once_s*) */

void handle_mdns_query_notifitcation(mdns_search_once_s *param_1)

{
  mdns_search_once_s *apmStack_24 [3];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 1;
  uStack_14 = 0;
  apmStack_24[0] = param_1;
  xQueueGenericSend(s_mdns_result_queue,apmStack_24,0xffffffff,0);
  write(s_mdns_event_fd,&uStack_18,8);
  return;
}

