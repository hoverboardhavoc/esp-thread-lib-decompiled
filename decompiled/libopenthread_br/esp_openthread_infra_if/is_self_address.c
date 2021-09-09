/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> is_self_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_self_address(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = s_netif;
  iVar2 = 0;
  iVar4 = s_netif + 0x4c;
  while (((*(byte *)(iVar1 + iVar2 + 0x10c) & 0x10) == 0 ||
         (iVar3 = memcmp(param_1,(void *)(iVar2 * 0x18 + iVar4),0x10), iVar3 != 0))) {
    iVar2 = iVar2 + 1;
    if (iVar2 == 8) {
      return 0;
    }
  }
  return 1;
}

