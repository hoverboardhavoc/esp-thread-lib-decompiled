/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> handle_udp_recv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void handle_udp_recv(void *ctx,udp_pcb *pcb,pbuf *p,ip_addr_t *addr,uint16_t port)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *__ptr;
  uint uVar5;
  int iVar6;
  u32_t uVar7;
  u32_t uVar8;
  u32_t uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  __ptr = (undefined4 *)malloc(0x24);
  iVar4 = _esp_openthread_task_queue_post;
  iVar3 = _esp_netif_get_netif_impl_index;
  iVar6 = _ip_data;
  if (__ptr == (undefined4 *)0x0) {
    otLogCrit(0xc,"-PLAT----: ","Failed to allocate recv task when receiving OpenThread plat UDP");
  }
  *__ptr = ctx;
  __ptr[1] = p;
  uVar7 = (addr->u_addr).ip6.addr[1];
  uVar8 = (addr->u_addr).ip6.addr[2];
  uVar9 = (addr->u_addr).ip6.addr[3];
  uVar10 = *(undefined4 *)((int)&addr->u_addr + 0x10);
  uVar11 = *(undefined4 *)&addr->type;
  __ptr[2] = (addr->u_addr).ip6.addr[0];
  __ptr[3] = uVar7;
  __ptr[4] = uVar8;
  __ptr[5] = uVar9;
  __ptr[6] = uVar10;
  __ptr[7] = uVar11;
  *(uint16_t *)(__ptr + 8) = port;
  if (addr->type == '\x06') {
    uVar1 = *(undefined1 *)(iVar4 + 7);
  }
  else {
    uVar1 = *(undefined1 *)(iVar3 + 8);
  }
  *(undefined1 *)((int)__ptr + 0x22) = uVar1;
  bVar2 = *(byte *)(iVar6 + 0x196);
  esp_openthread_get_backbone_netif();
  uVar5 = esp_netif_get_netif_impl_index();
  *(bool *)((int)__ptr + 0x23) = (bVar2 + 1 & 0xff) == uVar5;
  iVar6 = esp_openthread_task_queue_post(udp_recv_task,__ptr);
  if (iVar6 != 0) {
    free(__ptr);
  }
  return;
}

