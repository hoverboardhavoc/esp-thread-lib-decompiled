/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_task_queue_post(esp_openthread_task_t task,void *arg)

{
  int iVar1;
  ssize_t sVar2;
  esp_err_t eVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 local_20;
  uint64_t val;
  task_storage_t task_storage;
  
  local_20 = 1;
  val._0_4_ = 0;
  val._4_4_ = task;
  task_storage.task = (esp_openthread_task_t)arg;
  iVar1 = xQueueGenericSend(s_task_queue,(int)&val + 4,0xffffffff,0);
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar4,"OPENTHREAD","esp_openthread_task_queue_post",0x36);
    eVar3 = -1;
  }
  else {
    sVar2 = write(s_task_queue_event_fd,&local_20,8);
    if (sVar2 != 8) {
      iVar5 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_task_queue.c"
                            ,0x38,"esp_openthread_task_queue_post","ret == sizeof(val)");
      iVar1 = s_task_queue_event_fd;
      if (-1 < s_task_queue_event_fd) {
        if ((uint)s_task_queue_event_fd < 0x40) {
          puVar6 = (uint *)(((uint)s_task_queue_event_fd >> 5) * 4 + iVar5);
          *puVar6 = *puVar6 | 1 << (s_task_queue_event_fd & 0x1fU);
        }
        if (*(int *)(iVar5 + 0x18) < iVar1) {
          *(int *)(iVar5 + 0x18) = iVar1;
        }
      }
      return iVar5;
    }
    eVar3 = 0;
  }
  return eVar3;
}

