/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_task_queue_init(void)

{
  esp_err_t eVar1;
  undefined4 uVar2;
  
  s_task_queue_event_fd = eventfd(0,0x10);
  if (s_task_queue_event_fd < 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD","esp_openthread_task_queue_init",0x25);
    eVar1 = -1;
  }
  else {
    s_task_queue = (QueueHandle_t)xQueueGenericCreate(10,8,0);
    if (s_task_queue == (QueueHandle_t)0x0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_task_queue_init",0x28);
      eVar1 = 0x101;
    }
    else {
      eVar1 = 0;
    }
  }
  return eVar1;
}

