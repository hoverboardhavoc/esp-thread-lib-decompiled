/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_rebind_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* nat64_rebind_netif(void*) */

undefined4 nat64_rebind_netif(void *param_1)

{
  undefined4 uVar1;
  
  esp_openthread_get_backbone_netif();
  uVar1 = to_underlying_lwip_netif();
  raw_bind_netif(s_backbone_raw_pcb,uVar1);
  raw_bind_netif(s_backbone_icmp_raw_pcb,uVar1);
  netif_set_up(s_nat64_netif);
  return 0;
}

