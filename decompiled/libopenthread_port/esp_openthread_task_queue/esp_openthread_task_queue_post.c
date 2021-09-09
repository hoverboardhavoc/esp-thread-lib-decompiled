/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_post
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_post(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  ssize_t sVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0;
  local_20 = 1;
  uStack_18 = param_1;
  uStack_14 = param_2;
  iVar1 = xQueueGenericSend(s_task_queue,&uStack_18,0xffffffff,0);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_task_queue_post",0x39);
    uVar2 = 0xffffffff;
  }
  else {
    sVar3 = write(s_task_queue_event_fd,&local_20,8);
    uVar2 = 0;
    if (sVar3 != 8) {
      __assert_func(0,0,0,0);
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
  }
  return uVar2;
}

