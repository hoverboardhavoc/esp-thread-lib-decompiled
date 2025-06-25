/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> is_address_from_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_address_from_netif(void *param_1,int param_2)

{
  byte *__s2;
  byte *pbVar1;
  int iVar2;
  
  if ((*(byte *)(param_2 + 0x20f) & 1) == 0) {
    return 0;
  }
  __s2 = (byte *)(param_2 + 0x4c);
  pbVar1 = (byte *)(param_2 + 0x16c);
  while (((*pbVar1 & 0x10) == 0 || (iVar2 = memcmp(param_1,__s2,0x10), iVar2 != 0))) {
    __s2 = __s2 + 0x18;
    pbVar1 = pbVar1 + 1;
    if (__s2 == (byte *)(param_2 + 0x16c)) {
      return 0;
    }
  }
  return 1;
}

