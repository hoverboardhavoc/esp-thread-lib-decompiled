/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> send_mldv2_joinleave_netif.isra.5
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int send_mldv2_joinleave_netif_isra_5(void *param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_28 [24];
  
  iVar1 = pbuf_alloc(0x36,0x1c,0x280);
  if (iVar1 == 0) {
    iVar4 = 0x101;
  }
  else {
    puVar2 = (undefined1 *)memset(*(void **)(iVar1 + 4),0,6);
    *puVar2 = 0x8f;
    puVar2[7] = 1;
    puVar2[8] = (param_2 != 0) + '\x03';
    puVar2[6] = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    memcpy(puVar2 + 0xc,param_1,0x10);
    iVar4 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar4 + 0x46) = 1;
    uVar3 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar4,uVar3);
    memcpy(auStack_28,&_LANCHOR1,0x18);
    iVar4 = raw_sendto(s_icmp_send_pcb,iVar1,auStack_28);
    iVar4 = -(uint)(iVar4 != 0);
    pbuf_free(iVar1);
  }
  return iVar4;
}

