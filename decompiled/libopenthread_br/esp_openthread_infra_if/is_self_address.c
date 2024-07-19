/*
 * Last changed at upstream commit 203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * https://github.com/espressif/esp-thread-lib/commit/203c78501e9a6ea9ca3a929e6f9b6b9691ef16ee
 * Upstream date: 2024-07-19 18:50:00 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> is_self_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_self_address(void *param_1)

{
  byte *__s2;
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  
  pbVar1 = (byte *)(s_netif + 0x16c);
  __s2 = (byte *)(s_netif + 0x4c);
  pbVar2 = pbVar1;
  while (((*pbVar2 & 0x10) == 0 || (iVar3 = memcmp(param_1,__s2,0x10), iVar3 != 0))) {
    __s2 = __s2 + 0x18;
    pbVar2 = pbVar2 + 1;
    if (__s2 == pbVar1) {
      return 0;
    }
  }
  return 1;
}

