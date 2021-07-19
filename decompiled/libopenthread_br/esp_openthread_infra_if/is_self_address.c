/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> is_self_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_self_address(void *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (7 < uVar1) {
      return 0;
    }
    if (((*(byte *)(s_netif + uVar1 + 0x10c) & 0x10) != 0) &&
       (iVar2 = memcmp(param_1,(void *)(s_netif + uVar1 * 0x18 + 0x4c),0x10), iVar2 == 0)) break;
    uVar1 = uVar1 + 1;
  }
  return 1;
}

