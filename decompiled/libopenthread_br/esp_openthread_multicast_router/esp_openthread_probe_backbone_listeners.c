/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_28 [24];
  
  iVar4 = pbuf_alloc(0x36,0x28,0x280);
  iVar1 = 0x101;
  if (iVar4 != 0) {
    puVar2 = *(undefined1 **)(iVar4 + 4);
    memset(puVar2 + 2,0,0x26);
    *puVar2 = 0x82;
    puVar2[1] = 0;
    uVar3 = lwip_htons(1000);
    puVar2[4] = (char)uVar3;
    puVar2[5] = (char)((ushort)uVar3 >> 8);
    puVar2[6] = 0;
    puVar2[7] = 0;
    memcpy(auStack_28,&_L0,0x18);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uVar5 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar5);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar4,auStack_28);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar4);
  }
  return iVar1;
}

