/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_init(int param_1)

{
  undefined4 uVar1;
  
  s_task_queue_event_fd = eventfd(0,0x10);
  if (s_task_queue_event_fd < 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD","esp_openthread_task_queue_init",0x28);
    uVar1 = 0xffffffff;
  }
  else {
    s_task_queue = xQueueGenericCreate(*(undefined1 *)(param_1 + 0x5d),8,0);
    if (s_task_queue == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD","esp_openthread_task_queue_init",0x2b);
      uVar1 = 0x101;
    }
    else {
      uVar1 = esp_openthread_platform_workflow_register
                        (0x10000,esp_openthread_task_queue_process,"task_queue");
    }
  }
  return uVar1;
}

