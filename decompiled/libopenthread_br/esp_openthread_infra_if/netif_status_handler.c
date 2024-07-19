/*
 * Last changed at upstream commit 203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * https://github.com/espressif/esp-thread-lib/commit/203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * Upstream date: 2024-07-19 18:50:00 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> netif_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void netif_status_handler(void)

{
  int iVar1;
  
  iVar1 = esp_openthread_task_queue_post(handle_netif_state_task,0);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

