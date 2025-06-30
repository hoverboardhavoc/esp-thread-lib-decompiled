/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  int iVar6;
  int iVar7;
  void *__src;
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
      memset(puVar3 + 1,0,7);
      *puVar3 = 0x8f;
      puVar3[6] = (char)(uVar4 >> 8);
      iVar6 = s_netif_listener_lists;
      puVar3[7] = (char)uVar4;
      puVar3 = puVar3 + 8;
      for (; iVar1 = s_icmp_send_pcb, iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
        for (__src = *(void **)(iVar6 + 4); __src != (void *)0x0;
            __src = *(void **)((int)__src + 0x18)) {
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
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

