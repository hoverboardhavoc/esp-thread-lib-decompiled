/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
    esp_log(1,0x10000,
            "E (%lu) %s: %s(%d): Error handling OpenThread multicast listener: No enough memory\n",
            uVar1,0x10000,"esp_openthread_handle_thread_multicast_listener",0x31);
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
      esp_log(1,0x10000,"E (%lu) %s: Unknown OpenThread multicast listener event\n",uVar1,0x10000);
      return;
    }
    esp_openthread_task_switching_lock_release();
    pcVar2 = remove_multicast_listener_task;
  }
  tcpip_callback(pcVar2,__dest);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

