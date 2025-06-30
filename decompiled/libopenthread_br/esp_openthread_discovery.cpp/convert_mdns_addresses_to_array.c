/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> convert_mdns_addresses_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* convert_mdns_addresses_to_array(mdns_ip_addr_s*) */

void * convert_mdns_addresses_to_array(mdns_ip_addr_s *param_1)

{
  int iVar1;
  size_t __nmemb;
  void *pvVar2;
  int iVar3;
  
  __nmemb = get_mdns_num_ipv6_addresses(param_1);
  pvVar2 = calloc(__nmemb,0x10);
  iVar1 = 0;
  for (; param_1 != (mdns_ip_addr_s *)0x0; param_1 = *(mdns_ip_addr_s **)(param_1 + 0x18)) {
    if ((param_1[0x14] == (mdns_ip_addr_s)0x6) &&
       (iVar3 = esp_netif_ip6_get_addr_type(param_1), iVar3 != 2)) {
      memcpy((void *)(iVar1 * 0x10 + (int)pvVar2),param_1,0x10);
      iVar1 = iVar1 + 1;
    }
  }
  return pvVar2;
}

