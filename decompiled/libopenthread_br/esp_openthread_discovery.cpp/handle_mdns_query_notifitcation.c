/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  
  uStack_14 = 0;
  uStack_18 = 1;
  apmStack_24[0] = param_1;
  xQueueGenericSend(s_mdns_result_queue,apmStack_24,0xffffffff,0);
  write(s_mdns_event_fd,&uStack_18,8);
  return;
}

