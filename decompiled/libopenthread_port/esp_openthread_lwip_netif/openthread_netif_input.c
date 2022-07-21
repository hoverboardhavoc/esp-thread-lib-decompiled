/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
 * Source: libopenthread_port -> esp_openthread_lwip_netif.o -> openthread_netif_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void openthread_netif_input(int param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x187) & 1) != 0) {
    iVar1 = pbuf_alloc(0xe,param_3,0x182);
    if (iVar1 != 0) {
      otMessageRead(param_2,0,*(undefined4 *)(iVar1 + 4),param_3);
      iVar2 = (**(code **)(param_1 + 0x154))(iVar1,param_1,*(code **)(param_1 + 0x154));
      if (iVar2 != 0) {
        pbuf_free(iVar1);
        return;
      }
    }
  }
  return;
}

