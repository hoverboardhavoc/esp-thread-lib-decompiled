/*
 * Last changed at upstream commit 5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * https://github.com/espressif/esp-thread-lib/commit/5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * Upstream date: 2024-05-23 11:00:44 +0800
 * Upstream subject: feat(br): update border router lib
 * Source: libopenthread_br -> esp_openthread_multicast_adapter.o -> esp_openthread_handle_thread_multicast_listener
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_handle_thread_multicast_listener(int param_1,void *param_2)

{
  void *__dest;
  undefined4 uVar1;
  code *pcVar2;
  
  __dest = malloc(0x14);
  if (__dest == (void *)0x0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC3,uVar1,0x10000,"esp_openthread_handle_thread_multicast_listener",
                  0x31);
    return;
  }
  memcpy(__dest,param_2,0x10);
  *(undefined1 *)((int)__dest + 0x10) = 0;
  if (param_1 == 0) {
    esp_openthread_task_switching_lock_release();
    pcVar2 = add_multicast_listener_task;
  }
  else {
    if (param_1 != 1) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC4,uVar1,0x10000);
      return;
    }
    esp_openthread_task_switching_lock_release();
    pcVar2 = remove_multicast_listener_task;
  }
  tcpip_callback(pcVar2,__dest);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

