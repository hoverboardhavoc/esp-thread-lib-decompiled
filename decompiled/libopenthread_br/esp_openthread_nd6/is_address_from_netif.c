/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_nd6.o -> is_address_from_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_address_from_netif(void *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  byte *__s2;
  
  if ((*(byte *)(param_2 + 0x20f) & 1) == 0) {
    return 0;
  }
  __s2 = (byte *)(param_2 + 0x4c);
  pbVar1 = (byte *)(param_2 + 0x16c);
  while (((*pbVar1 & 0x10) == 0 || (iVar2 = memcmp(param_1,__s2,0x10), iVar2 != 0))) {
    __s2 = __s2 + 0x18;
    pbVar1 = pbVar1 + 1;
    if ((byte *)(param_2 + 0x16c) == __s2) {
      return 0;
    }
  }
  return 1;
}

