/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> convert_mdns_addresses_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* convert_mdns_addresses_to_array(mdns_result_s const*) */

void * convert_mdns_addresses_to_array(mdns_result_s *param_1)

{
  void *__src;
  size_t __nmemb;
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  __nmemb = get_mdns_num_ipv6_addresses(*(mdns_result_s **)(param_1 + 0x30));
  pvVar1 = calloc(__nmemb,0x10);
  iVar3 = 0;
  for (__src = *(void **)(param_1 + 0x30); __src != (void *)0x0;
      __src = *(void **)((int)__src + 0x18)) {
    if ((*(char *)((int)__src + 0x14) == '\x06') &&
       (iVar2 = esp_netif_ip6_get_addr_type(__src), iVar2 != 2)) {
      memcpy((void *)(iVar3 * 0x10 + (int)pvVar1),__src,0x10);
      iVar3 = iVar3 + 1;
    }
  }
  return pvVar1;
}

