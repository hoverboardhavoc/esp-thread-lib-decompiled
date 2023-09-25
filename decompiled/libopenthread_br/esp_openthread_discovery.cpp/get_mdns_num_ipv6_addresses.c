/*
 * Last changed at upstream commit 12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * https://github.com/espressif/esp-thread-lib/commit/12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * Upstream date: 2023-09-25 16:27:03 +0800
 * Upstream subject: lib(openthread): update otbr lib
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> get_mdns_num_ipv6_addresses
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* get_mdns_num_ipv6_addresses(mdns_ip_addr_s*) */

char get_mdns_num_ipv6_addresses(mdns_ip_addr_s *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  for (; param_1 != (mdns_ip_addr_s *)0x0; param_1 = *(mdns_ip_addr_s **)(param_1 + 0x18)) {
    if ((param_1[0x14] == (mdns_ip_addr_s)0x6) &&
       (iVar2 = esp_netif_ip6_get_addr_type(param_1), iVar2 != 2)) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

