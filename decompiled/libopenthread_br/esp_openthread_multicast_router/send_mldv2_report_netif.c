/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
  undefined1 auStack_38 [32];
  
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
      iVar6 = s_netif_listener_lists;
      puVar3[6] = (char)(uVar4 >> 8);
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
      memcpy(auStack_38,&_LANCHOR0,0x18);
      iVar6 = raw_sendto(s_icmp_send_pcb,iVar7,auStack_38);
      uVar2 = -(uint)(iVar6 != 0) | 1;
      pbuf_free(iVar7);
    }
  }
  return uVar2;
}

