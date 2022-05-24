/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  size_t __nmemb;
  void *pvVar1;
  int iVar2;
  
  __src = *(mdns_result_s **)(param_1 + 0x30);
  __nmemb = get_mdns_num_ipv6_addresses(__src);
  pvVar1 = calloc(__nmemb,0x10);
  iVar2 = 0;
  for (; __src != (mdns_result_s *)0x0; __src = *(mdns_result_s **)(__src + 0x18)) {
    if (__src[0x14] == (mdns_result_s)0x6) {
      memcpy((void *)(iVar2 * 0x10 + (int)pvVar1),__src,0x10);
      iVar2 = iVar2 + 1;
    }
  }
  return pvVar1;
}

