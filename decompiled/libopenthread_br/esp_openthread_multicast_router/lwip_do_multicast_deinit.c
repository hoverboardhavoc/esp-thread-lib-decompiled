/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> lwip_do_multicast_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_do_multicast_deinit(void)

{
  if (s_udp_send_pcb != 0) {
    raw_remove();
  }
  if (s_icmp_send_pcb != 0) {
    raw_remove();
  }
  free_all_netif_listener_list();
  return 0;
}

