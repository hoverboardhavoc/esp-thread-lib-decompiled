/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
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
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar3 = pbuf_alloc(0x36,0x28,0x280);
  iVar1 = 0x101;
  if (iVar3 != 0) {
    puVar2 = *(undefined1 **)(iVar3 + 4);
    memset(puVar2 + 1,0,0x27);
    *puVar2 = 0x82;
    *(undefined2 *)(puVar2 + 4) = 0xe803;
    iVar1 = s_icmp_send_pcb;
    uStack_28 = 0x2ff;
    uStack_1c = 0x1000000;
    uStack_14 = 6;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_18 = 0;
    uVar4 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar4);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar3,&uStack_28);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar3);
  }
  return iVar1;
}

