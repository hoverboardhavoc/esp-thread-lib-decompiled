/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> handle_mdns_query_notification
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* handle_mdns_query_notification(mdns_search_once_s*) */

void handle_mdns_query_notification(mdns_search_once_s *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 1;
  uStack_14 = 0;
  puVar2 = (undefined4 *)malloc(8);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to queue completed mDNS search %p\n",uVar3,
            "handle_mdns_query_notification",0xce,param_1);
  }
  else {
    *puVar2 = param_1;
    puVar2[1] = 0;
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    puVar1 = puVar2;
    if (s_completed_searches_tail != (undefined4 *)0x0) {
      s_completed_searches_tail[1] = puVar2;
      puVar1 = s_completed_searches_head;
    }
    s_completed_searches_head = puVar1;
    s_completed_searches_tail = puVar2;
    esp_openthread_task_switching_lock_release();
    write(s_mdns_event_fd,&uStack_18,8);
  }
  return;
}

