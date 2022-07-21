/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
 * Source: libopenthread_port -> esp_openthread_lwip_netif.o -> openthread_output_ip6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 openthread_output_ip6(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = esp_netif_get_handle_from_netif_impl();
  uVar3 = 0xfffffff4;
  if (iVar1 != 0) {
    if (*param_1 == 0) {
      iVar1 = esp_netif_transmit(param_1[1],*(undefined2 *)((int)param_1 + 10));
    }
    else {
      iVar2 = pbuf_alloc(0,(short)param_1[2],0x280);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      pbuf_copy(param_1);
      iVar1 = esp_netif_transmit(iVar1,*(undefined4 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 10));
      pbuf_free(iVar2);
    }
    uVar3 = 0;
    if ((iVar1 != 0) && (uVar3 = 0xfffffff3, iVar1 == 0x101)) {
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

