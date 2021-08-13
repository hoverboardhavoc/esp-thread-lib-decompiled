/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_deinit(void)

{
  if (s_task_queue != 0) {
    vQueueDelete();
    s_task_queue = 0;
  }
  if (-1 < s_task_queue_event_fd) {
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  esp_openthread_platform_workflow_unregister("task_queue");
  return 0;
}

