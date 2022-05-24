/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  
  pbVar1 = (byte *)(s_netif + 0x10c);
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

