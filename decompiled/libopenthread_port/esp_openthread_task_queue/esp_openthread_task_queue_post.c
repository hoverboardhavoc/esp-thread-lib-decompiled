/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_task_queue_post(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  ssize_t sVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = 1;
  uStack_1c = 0;
  uStack_18 = param_1;
  uStack_14 = param_2;
  iVar2 = xQueueGenericSend(s_task_queue,&uStack_18,0xffffffff,0);
  if (iVar2 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar4,"OPENTHREAD","esp_openthread_task_queue_post",0x37);
    iVar2 = -1;
  }
  else {
    sVar3 = write(s_task_queue_event_fd,&local_20,8);
    if (sVar3 != 8) {
      iVar2 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_task_queue.c"
                            ,0x39,"esp_openthread_task_queue_post","ret == sizeof(val)");
      uVar1 = s_task_queue_event_fd;
      if (-1 < (int)s_task_queue_event_fd) {
        if (s_task_queue_event_fd < 0x40) {
          puVar5 = (uint *)((s_task_queue_event_fd >> 5) * 4 + iVar2);
          *puVar5 = *puVar5 | 1 << (s_task_queue_event_fd & 0x1f);
        }
        if (*(int *)(iVar2 + 0x18) < (int)uVar1) {
          *(uint *)(iVar2 + 0x18) = uVar1;
        }
      }
      return iVar2;
    }
    iVar2 = 0;
  }
  return iVar2;
}

