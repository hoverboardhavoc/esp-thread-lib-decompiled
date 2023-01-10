/*
 * Last changed at upstream commit 7d57b18006da6e182ddb87698abdced1566f3b56
 * https://github.com/espressif/esp-thread-lib/commit/7d57b18006da6e182ddb87698abdced1566f3b56
 * Upstream date: 2023-01-10 14:40:17 +0800
 * Upstream subject: openthread: add thread_br lib for esp32c2 and esp32c6 * esp_openthread: c558ac0 * ot-repo: 19e1875
 * Source: libopenthread_br -> esp_openthread_net_utils.o -> to_underlying_lwip_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void to_underlying_lwip_netif(void)

{
  undefined1 uVar1;
  
  uVar1 = esp_netif_get_netif_impl_index();
  netif_get_by_index(uVar1);
  return;
}

