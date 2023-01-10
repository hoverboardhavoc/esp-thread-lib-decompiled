/*
 * Last changed at upstream commit 7d57b18006da6e182ddb87698abdced1566f3b56
 * https://github.com/espressif/esp-thread-lib/commit/7d57b18006da6e182ddb87698abdced1566f3b56
 * Upstream date: 2023-01-10 14:40:17 +0800
 * Upstream subject: openthread: add thread_br lib for esp32c2 and esp32c6 * esp_openthread: c558ac0 * ot-repo: 19e1875
 * Source: libopenthread_br -> nat64_netif.cpp.o -> netif_init_internal
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* netif_init_internal(netif*) */

int netif_init_internal(netif *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cStack_29;
  undefined1 auStack_28 [15];
  undefined1 uStack_19;
  
  nat64_get_prefix(auStack_28);
  cStack_29 = -1;
  *(undefined2 *)(param_1 + 0x188) = 0x746e;
  param_1[0x186] = (netif)0x6;
  *(undefined2 *)(param_1 + 0x17c) = 0x500;
  *(code **)(param_1 + 0x160) = nat64_translate_ip6;
  *(undefined4 *)(param_1 + 0x158) = 0;
  uStack_19 = 1;
  iVar1 = netif_add_ip6_address(s_nat64_netif,auStack_28,&cStack_29);
  if ((iVar1 == 0) && (-1 < cStack_29)) {
    netif_ip6_addr_set_state(s_nat64_netif,0x30);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"NAT64",&_LC4,uVar2,"NAT64","netif_init_internal",0xa9);
  }
  return iVar1;
}

