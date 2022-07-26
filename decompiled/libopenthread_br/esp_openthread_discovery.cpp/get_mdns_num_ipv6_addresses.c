/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> get_mdns_num_ipv6_addresses
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* get_mdns_num_ipv6_addresses(mdns_result_s const*) [clone .isra.0] */

char get_mdns_num_ipv6_addresses(mdns_result_s *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  for (; param_1 != (mdns_result_s *)0x0; param_1 = *(mdns_result_s **)(param_1 + 0x18)) {
    if ((param_1[0x14] == (mdns_result_s)0x6) &&
       (iVar2 = esp_netif_ip6_get_addr_type(param_1), iVar2 != 2)) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

