/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_joinleave_netif.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int send_mldv2_joinleave_netif_constprop_0(void *param_1,char param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_38 [32];
  
  iVar3 = pbuf_alloc(0x36,0x1c,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    puVar2 = *(undefined1 **)(iVar3 + 4);
    memset(puVar2 + 1,0,7);
    *puVar2 = 0x8f;
    puVar2[8] = param_2 + '\x03';
    puVar2[7] = 1;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    memcpy(puVar2 + 0xc,param_1,0x10);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uVar4 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar4);
    memcpy(auStack_38,&_L0,0x18);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,auStack_38);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

