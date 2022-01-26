/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar1,"OPENTHREAD",
                  "esp_openthread_handle_thread_multicast_listener",0x31);
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
      esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD");
      return;
    }
    pcVar2 = remove_multicast_listener_task;
  }
  tcpip_callback(pcVar2,__dest);
  return;
}

