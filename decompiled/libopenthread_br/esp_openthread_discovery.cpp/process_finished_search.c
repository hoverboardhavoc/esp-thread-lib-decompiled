/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> process_finished_search
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* process_finished_search(mdns_search_once_s*, mdns_result_s*) */

void process_finished_search(mdns_search_once_s *param_1,mdns_result_s *param_2)

{
  pending_query_t *__ptr;
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = s_pending_queries;
  __ptr = (pending_query_t *)s_pending_queries._812_4_;
  while (__ptr != (pending_query_t *)0x0) {
    if ((*(mdns_search_once_s **)(__ptr + 800) == param_1) ||
       (*(mdns_search_once_s **)(__ptr + 0x324) == param_1)) {
      if (*(mdns_search_once_s **)(__ptr + 800) == param_1) {
        *(undefined4 *)(__ptr + 800) = 0;
      }
      if (*(mdns_search_once_s **)(__ptr + 0x324) == param_1) {
        *(undefined4 *)(__ptr + 0x324) = 0;
      }
      iVar1 = *(int *)(__ptr + 0x328);
      if (iVar1 == 1) {
        process_finished_service(__ptr,param_1,param_2);
      }
      else if (iVar1 == 0) {
        process_finished_browse(__ptr,param_1,param_2);
      }
      else if (iVar1 == 2) {
        process_finished_host(__ptr,param_1,param_2);
      }
    }
    if ((*(int *)(__ptr + 800) == 0) && (*(int *)(__ptr + 0x324) == 0)) {
      *(undefined4 *)(puVar2 + 0x32c) = *(undefined4 *)(__ptr + 0x32c);
      free(__ptr);
      __ptr = *(pending_query_t **)(puVar2 + 0x32c);
    }
    else {
      puVar2 = *(undefined1 **)(puVar2 + 0x32c);
      __ptr = *(pending_query_t **)(__ptr + 0x32c);
    }
  }
  return;
}

