/*
 * Last changed at upstream commit af5d67ed3acb06cac9e06986b08781b93bd6dade
 * https://github.com/espressif/esp-thread-lib/commit/af5d67ed3acb06cac9e06986b08781b93bd6dade
 * Upstream date: 2023-01-09 11:37:28 +0100
 * Upstream subject: lib: Address lwip thread safety
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> infra_if_do_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 infra_if_do_deinit(void)

{
  raw_remove(s_raw_pcb);
  s_raw_pcb = 0;
  netif_set_status_callback(s_netif,0);
  s_netif = 0;
  return 0;
}

