/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_probe_backbone_listeners
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_probe_backbone_listeners(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 auStack_28 [24];
  
  iVar2 = pbuf_alloc(0x36,0x28,0x280);
  iVar1 = 0x101;
  if (iVar2 != 0) {
    puVar3 = (undefined1 *)memset(*(void **)(iVar2 + 4),0,0x28);
    *puVar3 = 0x82;
    puVar3[4] = 3;
    puVar3[5] = 0xe8;
    memcpy(auStack_28,&_LANCHOR2,0x18);
    iVar1 = s_icmp_send_pcb;
    *(undefined2 *)(s_icmp_send_pcb + 0x44) = 2;
    *(undefined1 *)(iVar1 + 0x46) = 1;
    uVar4 = esp_openthread_get_lwip_backbone_netif();
    raw_bind_netif(iVar1,uVar4);
    iVar1 = raw_sendto(s_icmp_send_pcb,iVar2,auStack_28);
    iVar1 = -(uint)(iVar1 != 0);
    pbuf_free(iVar2);
  }
  return iVar1;
}

