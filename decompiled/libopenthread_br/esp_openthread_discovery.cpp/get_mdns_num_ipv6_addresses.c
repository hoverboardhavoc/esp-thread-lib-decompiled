/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> get_mdns_num_ipv6_addresses
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* get_mdns_num_ipv6_addresses(mdns_result_s const*) */

char get_mdns_num_ipv6_addresses(mdns_result_s *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  for (iVar2 = *(int *)(param_1 + 0x30); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18)) {
    if (*(char *)(iVar2 + 0x14) == '\x06') {
      cVar1 = cVar1 + '\x01';
    }
  }
  return cVar1;
}

