/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_post(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20 = 1;
  uStack_1c = 0;
  uStack_18 = param_1;
  uStack_14 = param_2;
  iVar1 = xQueueGenericSend(s_task_queue,&uStack_18,0xffffffff,0);
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC7,uVar3,"OPENTHREAD","esp_openthread_task_queue_post",0x3a);
    uVar3 = 0xffffffff;
  }
  else {
    sVar2 = write(s_task_queue_event_fd,&local_20,8);
    if (sVar2 != 8) {
      __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_task_queue.c"
                    ,0x3c,"esp_openthread_task_queue_post","ret == sizeof(val)");
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
    uVar3 = 0;
  }
  return uVar3;
}

