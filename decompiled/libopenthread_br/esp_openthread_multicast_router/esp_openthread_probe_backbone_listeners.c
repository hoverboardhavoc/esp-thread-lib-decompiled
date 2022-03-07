/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_probe_backbone_listeners
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_probe_backbone_listeners(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_28 [24];
  
  iVar3 = pbuf_alloc(0x36,0x28,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    puVar2 = *(undefined1 **)(iVar3 + 4);
    memset(puVar2 + 2,0,0x26);
    *puVar2 = 0x82;
    puVar2[4] = 3;
    puVar2[5] = 0xe8;
    puVar2[1] = 0;
    memcpy(auStack_28,&_LANCHOR1,0x18);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uVar4 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar4);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,auStack_28);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

