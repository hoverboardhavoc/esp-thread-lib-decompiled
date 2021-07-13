/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_process(int param_1)

{
  int iVar1;
  ssize_t sVar2;
  undefined4 uVar3;
  undefined1 auStack_20 [8];
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (((s_task_queue_event_fd < 0x40) &&
      ((*(uint *)(param_1 + (s_task_queue_event_fd >> 5) * 4) & 1 << (s_task_queue_event_fd & 0x1f))
       != 0)) && (sVar2 = read(s_task_queue_event_fd,auStack_20,8), sVar2 != 8)) {
    __assert_func("/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_task_queue.c"
                  ,0x4f,"esp_openthread_task_queue_process","ret == sizeof(val)");
  }
  else if (s_task_queue != 0) {
    while (iVar1 = xQueueReceive(s_task_queue,&pcStack_18,0), iVar1 == 1) {
      (*pcStack_18)(uStack_14,pcStack_18);
    }
    return 0;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD","esp_openthread_task_queue_process",0x53);
  return 0x103;
}

