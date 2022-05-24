/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_task_queue_process(int param_1)

{
  ssize_t sVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (((s_task_queue_event_fd < 0x40) &&
      ((1 << (s_task_queue_event_fd & 0x1f) &
       *(uint *)(param_1 + ((int)s_task_queue_event_fd >> 5) * 4)) != 0)) &&
     (sVar1 = read(s_task_queue_event_fd,&pcStack_18,8), sVar1 != 8)) {
    __assert_func(0,0,0,0);
  }
  if (s_task_queue == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD","esp_openthread_task_queue_process",0x54);
    uVar2 = 0x103;
  }
  else {
    while (iVar3 = xQueueReceive(s_task_queue,&pcStack_18,0), iVar3 == 1) {
      (*pcStack_18)(uStack_14,pcStack_18);
    }
    uVar2 = 0;
  }
  return uVar2;
}

