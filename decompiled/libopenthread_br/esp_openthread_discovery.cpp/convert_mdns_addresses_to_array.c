/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> convert_mdns_addresses_to_array
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* convert_mdns_addresses_to_array(mdns_result_s const*) */

void * convert_mdns_addresses_to_array(mdns_result_s *param_1)

{
  mdns_result_s *__src;
  int iVar1;
  size_t __nmemb;
  void *pvVar2;
  
  __src = *(mdns_result_s **)(param_1 + 0x30);
  __nmemb = get_mdns_num_ipv6_addresses(__src);
  pvVar2 = calloc(__nmemb,0x10);
  iVar1 = 0;
  for (; __src != (mdns_result_s *)0x0; __src = *(mdns_result_s **)(__src + 0x18)) {
    if (__src[0x14] == (mdns_result_s)0x6) {
      memcpy((void *)(iVar1 * 0x10 + (int)pvVar2),__src,0x10);
      iVar1 = iVar1 + 1;
    }
  }
  return pvVar2;
}

