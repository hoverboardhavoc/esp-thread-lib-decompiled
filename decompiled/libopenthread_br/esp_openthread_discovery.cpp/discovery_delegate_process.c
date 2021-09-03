/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> discovery_delegate_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* discovery_delegate_process(otInstance*, esp_openthread_mainloop_context_t const*) */

undefined4
discovery_delegate_process(otInstance *param_1,esp_openthread_mainloop_context_t *param_2)

{
  int iVar1;
  mdns_search_once_s *local_20;
  mdns_result_s *pmStack_1c;
  undefined1 auStack_18 [20];
  
  if (((-1 < (int)s_mdns_event_fd) && (s_mdns_event_fd < 0x40)) &&
     ((*(uint *)(param_2 + (s_mdns_event_fd >> 5) * 4) & 1 << (s_mdns_event_fd & 0x1f)) != 0)) {
    read(s_mdns_event_fd,auStack_18,8);
    while (iVar1 = xQueueReceive(s_mdns_result_queue,&local_20,0), iVar1 == 1) {
      mdns_query_async_get_results(local_20,0xffffffff,&pmStack_1c);
      process_finished_search(local_20,pmStack_1c);
      mdns_query_results_free(pmStack_1c);
      mdns_query_async_delete(local_20);
    }
    return 0;
  }
  return 0;
}

