/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD","esp_openthread_task_queue_init",0x26);
    uVar1 = 0xffffffff;
  }
  else {
    s_task_queue = xQueueGenericCreate(*(undefined1 *)(param_1 + 0x5d),8,0);
    if (s_task_queue == 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar1,"OPENTHREAD","esp_openthread_task_queue_init",0x29);
      uVar1 = 0x101;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

