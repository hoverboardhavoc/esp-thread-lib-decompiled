/*
 * Last changed at upstream commit 203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * https://github.com/espressif/esp-thread-lib/commit/203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * Upstream date: 2024-07-19 18:50:00 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> handle_netif_receive_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_netif_receive_task(void *param_1)

{
  esp_openthread_get_instance();
  otPlatInfraIfRecvIcmp6Nd
            (*(char *)(s_netif + 0x20e) + '\x01',param_1,*(undefined4 *)((int)param_1 + 0x14),
             *(undefined2 *)((int)param_1 + 0x18));
  free(*(void **)((int)param_1 + 0x14));
  free(param_1);
  return;
}

