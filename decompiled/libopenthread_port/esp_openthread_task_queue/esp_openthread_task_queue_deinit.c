/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_task_queue_deinit(void)

{
  if (s_task_queue != (QueueHandle_t)0x0) {
    vQueueDelete();
    s_task_queue = (QueueHandle_t)0x0;
  }
  if (-1 < s_task_queue_event_fd) {
    close(s_task_queue_event_fd);
    s_task_queue_event_fd = -1;
  }
  return 0;
}

