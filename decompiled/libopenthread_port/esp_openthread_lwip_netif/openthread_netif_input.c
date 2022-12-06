/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  int iVar3;
  
  if (param_2 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x187) & 1) != 0) {
    iVar1 = pbuf_alloc(0xe,param_3,0x182);
    if (iVar1 != 0) {
      iVar2 = otMessageRead(param_2,0,*(undefined4 *)(iVar1 + 4),param_3);
      iVar3 = otMessageGetLength(param_2);
      if ((iVar2 != iVar3) ||
         (iVar2 = (**(code **)(param_1 + 0x154))(iVar1,param_1,*(code **)(param_1 + 0x154)),
         iVar2 != 0)) {
        pbuf_free(iVar1);
        return;
      }
    }
  }
  return;
}

