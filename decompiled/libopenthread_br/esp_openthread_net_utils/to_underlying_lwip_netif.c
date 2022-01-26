/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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

