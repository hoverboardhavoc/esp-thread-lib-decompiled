/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> infra_if_do_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* infra_if_do_deinit(void*) */

undefined4 infra_if_do_deinit(void *param_1)

{
  raw_remove(s_raw_pcb);
  s_raw_pcb = 0;
  netif_set_status_callback(s_netif,0);
  s_netif = 0;
  return 0;
}

