/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
            (*(char *)(s_netif + 0x196) + '\x01',param_1,*(undefined4 *)((int)param_1 + 0x14),
             *(undefined2 *)((int)param_1 + 0x18));
  free(*(void **)((int)param_1 + 0x14));
  free(param_1);
  return;
}

