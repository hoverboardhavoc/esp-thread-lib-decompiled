/*
 * Last changed at upstream commit 75a1adad77ac6a3a45ec0806c4f680520823fdba
 * https://github.com/espressif/esp-thread-lib/commit/75a1adad77ac6a3a45ec0806c4f680520823fdba
 * Upstream date: 2026-05-19 03:52:07 +0000
 * Upstream subject: feat(openthread): support s31 openthread br lib
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> leave_multicast_group_on_backbone_netif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int leave_multicast_group_on_backbone_netif(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = esp_openthread_get_lwip_backbone_netif();
  if (iVar4 != param_1) {
    if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0x20f) & 5) == 5)) {
      iVar2 = pbuf_alloc(0x36,0x1c,0x280);
      if (iVar2 == 0) {
        iVar4 = 0x101;
      }
      else {
        puVar3 = *(undefined1 **)(iVar2 + 4);
        *(undefined2 *)(puVar3 + 5) = 0;
        *puVar3 = 0x8f;
        *(undefined2 *)(puVar3 + 6) = 0x100;
        puVar3[8] = 3;
        *(undefined4 *)(puVar3 + 1) = 0;
        puVar3[9] = 0;
        *(undefined2 *)(puVar3 + 10) = 0;
        memcpy(puVar3 + 0xc,param_2,0x10);
        iVar1 = s_icmp_send_pcb;
        *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
        *(undefined1 *)(iVar1 + 0x46) = 1;
        raw_bind_netif(iVar4);
        uStack_38 = 0x2ff;
        uStack_2c = 0x16000000;
        uStack_34 = 0;
        uStack_30 = 0;
        uStack_28 = 0;
        uStack_24 = 6;
        iVar4 = raw_sendto(s_icmp_send_pcb,iVar2,&uStack_38);
        iVar4 = -(uint)(iVar4 != 0);
        pbuf_free(iVar2);
      }
      return iVar4;
    }
    uVar5 = esp_log_timestamp();
    esp_log(2,"OPENTHREAD","W (%lu) %s: Skip multicast leave on unavailable backbone netif\n",uVar5)
    ;
  }
  return 0;
}

