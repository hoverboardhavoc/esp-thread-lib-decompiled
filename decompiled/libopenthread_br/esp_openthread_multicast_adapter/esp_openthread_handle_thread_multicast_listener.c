/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
                  0x30);
    return;
  }
  memcpy(__dest,param_2,0x10);
  *(undefined1 *)((int)__dest + 0x10) = 0;
  if (param_1 == 0) {
    pcVar2 = add_multicast_listener_task;
  }
  else {
    if (param_1 != 1) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC4,uVar1,0x10000);
      return;
    }
    pcVar2 = remove_multicast_listener_task;
  }
  tcpip_callback(pcVar2,__dest);
  return;
}

