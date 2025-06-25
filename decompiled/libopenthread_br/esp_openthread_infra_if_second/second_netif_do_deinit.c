/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> second_netif_do_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 second_netif_do_deinit(void)

{
  raw_remove(s_raw_pcb);
  s_raw_pcb = 0;
  netif_set_status_callback(s_netif,0);
  s_netif_ra_enabled = 0;
  return 0;
}

