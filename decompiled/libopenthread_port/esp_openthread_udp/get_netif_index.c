/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> get_netif_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 get_netif_index(int param_1)

{
  undefined1 uVar1;
  
  if (param_1 == 1) {
    esp_openthread_get_netif();
  }
  else {
    if (param_1 != 2) {
      return 0;
    }
    esp_openthread_get_backbone_netif();
  }
  uVar1 = esp_netif_get_netif_impl_index();
  return uVar1;
}

