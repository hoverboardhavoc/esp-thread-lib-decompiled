/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> esp_openthread_discovery_delegate_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_discovery_delegate_deinit(void)

{
  void *__ptr;
  void *pvVar1;
  
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  __ptr = s_completed_searches_head;
  s_completed_searches_head = (void *)0x0;
  s_completed_searches_tail = 0;
  esp_openthread_task_switching_lock_release();
  close(s_mdns_event_fd);
  s_mdns_event_fd = 0xffffffff;
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((int)__ptr + 4);
    free(__ptr);
    __ptr = pvVar1;
  }
  esp_openthread_get_instance();
  otDnssdQuerySetCallbacks(0,0,0);
  esp_openthread_platform_workflow_unregister("discovery");
  return;
}

