/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_infra_if_deinit(void)

{
  int iVar1;
  
  if (s_raw_pcb != 0) {
    raw_remove();
    s_raw_pcb = 0;
    netif_set_status_callback(s_netif,0);
    s_netif = 0;
    esp_openthread_get_instance();
    iVar1 = otBorderRoutingSetEnabled(0);
    if (iVar1 != 0) {
      iVar1 = -1;
    }
    return iVar1;
  }
  return 0x103;
}

