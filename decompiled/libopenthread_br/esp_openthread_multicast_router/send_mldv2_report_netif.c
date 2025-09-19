/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_report_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint send_mldv2_report_netif(void)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  void *__src;
  int iVar6;
  int iVar7;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar2 = 0x105;
  if (s_netif_listener_lists != 0) {
    uVar4 = 0;
    iVar7 = s_netif_listener_lists;
    do {
      for (iVar6 = *(int *)(iVar7 + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x18)) {
        uVar4 = uVar4 + 1 & 0xffff;
      }
      iVar7 = *(int *)(iVar7 + 8);
    } while (iVar7 != 0);
    uVar2 = 0x101;
    iVar7 = pbuf_alloc(0x36,uVar4 * 0x14 + 8 & 0xffff,0x280);
    if (iVar7 != 0) {
      puVar3 = *(undefined1 **)(iVar7 + 4);
      *puVar3 = 0x8f;
      *(undefined2 *)(puVar3 + 5) = 0;
      *(undefined4 *)(puVar3 + 1) = 0;
      iVar6 = s_netif_listener_lists;
      *(ushort *)(puVar3 + 6) = (ushort)(uVar4 << 8) | (ushort)(uVar4 >> 8);
      puVar3 = puVar3 + 8;
      for (; iVar1 = s_icmp_send_pcb, iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
        for (__src = *(void **)(iVar6 + 4); __src != (void *)0x0;
            __src = *(void **)((int)__src + 0x18)) {
          puVar3[1] = 0;
          *(undefined2 *)(puVar3 + 2) = 0;
          *puVar3 = 2;
          memcpy(puVar3 + 4,__src,0x10);
          puVar3 = puVar3 + 0x14;
        }
      }
      *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
      *(undefined1 *)(iVar1 + 0x46) = 1;
      uVar5 = esp_openthread_get_lwip_backbone_netif();
      raw_bind_netif(iVar1,uVar5);
      uStack_38 = 0x2ff;
      uStack_2c = 0x16000000;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_28 = 0;
      uStack_24 = 6;
      iVar6 = raw_sendto(s_icmp_send_pcb,iVar7,&uStack_38);
      uVar2 = -(uint)(iVar6 != 0) | 1;
      pbuf_free(iVar7);
    }
  }
  return uVar2;
}

