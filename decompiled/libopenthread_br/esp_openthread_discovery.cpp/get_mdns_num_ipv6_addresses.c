/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  
  cVar1 = '\0';
  for (; param_1 != (mdns_result_s *)0x0; param_1 = *(mdns_result_s **)(param_1 + 0x18)) {
    if (param_1[0x14] == (mdns_result_s)0x6) {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

