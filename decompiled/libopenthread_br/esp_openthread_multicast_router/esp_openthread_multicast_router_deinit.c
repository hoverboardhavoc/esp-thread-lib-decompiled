/*
 * Last changed at upstream commit 66e81acb8df80dbc52a2b0841a8ae3153557e131
 * https://github.com/espressif/esp-thread-lib/commit/66e81acb8df80dbc52a2b0841a8ae3153557e131
 * Upstream date: 2025-12-04 07:38:20 +0000
 * Upstream subject: fix(openthread): resolve deadlock issues due to switching_lock
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_router_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_multicast_router_deinit(void)

{
  s_multicast_router_initialized = 0;
  esp_openthread_task_switching_lock_release();
  esp_netif_tcpip_exec(lwip_do_multicast_deinit,0);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

