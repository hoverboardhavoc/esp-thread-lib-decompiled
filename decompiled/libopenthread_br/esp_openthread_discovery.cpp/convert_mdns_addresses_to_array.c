/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
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
  int iVar1;
  size_t __nmemb;
  void *pvVar2;
  
  __nmemb = get_mdns_num_ipv6_addresses(param_1);
  pvVar2 = calloc(__nmemb,0x10);
  iVar1 = 0;
  for (__src = *(void **)(param_1 + 0x30); __src != (void *)0x0;
      __src = *(void **)((int)__src + 0x18)) {
    if (*(char *)((int)__src + 0x14) == '\x06') {
      memcpy((void *)(iVar1 * 0x10 + (int)pvVar2),__src,0x10);
      iVar1 = iVar1 + 1;
    }
  }
  return pvVar2;
}

