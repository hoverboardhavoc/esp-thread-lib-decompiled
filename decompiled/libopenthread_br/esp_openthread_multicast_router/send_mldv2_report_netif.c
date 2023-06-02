/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_report_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 send_mldv2_report_netif(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  void *__src;
  undefined1 auStack_38 [32];
  
  uVar2 = 0x105;
  if (s_netif_listener_lists != 0) {
    uVar4 = 0;
    iVar6 = s_netif_listener_lists;
    do {
      for (iVar5 = *(int *)(iVar6 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x18)) {
        uVar4 = uVar4 + 1 & 0xffff;
      }
      iVar6 = *(int *)(iVar6 + 8);
    } while (iVar6 != 0);
    uVar2 = 0x101;
    iVar6 = pbuf_alloc(0x36,uVar4 * 0x14 + 8 & 0xffff,0x280);
    if (iVar6 != 0) {
      puVar3 = *(undefined1 **)(iVar6 + 4);
      memset(puVar3 + 1,0,7);
      *puVar3 = 0x8f;
      iVar5 = s_netif_listener_lists;
      puVar3[6] = (char)(uVar4 >> 8);
      puVar3[7] = (char)uVar4;
      puVar3 = puVar3 + 8;
      for (; iVar1 = s_icmp_send_pcb, iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
        for (__src = *(void **)(iVar5 + 4); __src != (void *)0x0;
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
      uVar2 = esp_openthread_get_lwip_backbone_netif();
      raw_bind_netif(iVar1,uVar2);
      memcpy(auStack_38,&_LANCHOR0,0x18);
      iVar5 = raw_sendto(s_icmp_send_pcb,iVar6,auStack_38);
      uVar2 = 0xffffffff;
      if (iVar5 == 0) {
        uVar2 = 1;
      }
      pbuf_free(iVar6);
    }
  }
  return uVar2;
}

