/*
 * Last changed at upstream commit 56af58057c259405aa90c478e294f6216cc2f6db
 * https://github.com/espressif/esp-thread-lib/commit/56af58057c259405aa90c478e294f6216cc2f6db
 * Upstream date: 2024-09-09 14:04:56 +0200
 * Upstream subject: update(ot_lib): Rebuild with lwip 2.2.0-esp
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
            (*(char *)(s_netif + 0x212) + '\x01',param_1,*(undefined4 *)((int)param_1 + 0x14),
             *(undefined2 *)((int)param_1 + 0x18));
  free(*(void **)((int)param_1 + 0x14));
  free(param_1);
  return;
}

