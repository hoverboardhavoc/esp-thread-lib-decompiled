/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_infra_if_deinit(void)

{
  int iVar1;
  
  iVar1 = 0x103;
  if (s_raw_pcb != 0) {
    raw_remove(s_raw_pcb);
    s_raw_pcb = 0;
    netif_set_status_callback(s_netif,0);
    s_netif = 0;
    esp_openthread_get_instance();
    iVar1 = otBorderRoutingSetEnabled(0);
    iVar1 = -(uint)(iVar1 != 0);
  }
  return iVar1;
}

