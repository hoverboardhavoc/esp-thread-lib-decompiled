/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_task_queue_process
                    (otInstance *instance,esp_openthread_mainloop_context_t *mainloop)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_20 [4];
  uint64_t val;
  task_storage_t task_storage;
  
  if ((((uint)s_task_queue_event_fd < 0x40) &&
      (((mainloop->read_fds).fds_bits[(uint)s_task_queue_event_fd >> 5] &
       1 << (s_task_queue_event_fd & 0x1fU)) != 0)) &&
     (sVar2 = read(s_task_queue_event_fd,auStack_20,8), sVar2 != 8)) {
    __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_task_queue.c"
                  ,0x4e,"esp_openthread_task_queue_process","ret == sizeof(val)");
  }
  else if (s_task_queue != (QueueHandle_t)0x0) {
    while (iVar1 = xQueueReceive(s_task_queue,(int)&val + 4,0), iVar1 == 1) {
      (*val._4_4_)(task_storage.task,val._4_4_);
    }
    return 0;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD","esp_openthread_task_queue_process",0x52);
  return 0x103;
}

