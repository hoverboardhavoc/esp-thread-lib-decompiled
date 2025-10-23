/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> handle_netif_receive_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* handle_netif_receive_task(void*) */

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

