/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> multicast_router_init_on_lwip_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint multicast_router_init_on_lwip_task(void)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [32];
  
  piVar3 = s_netif_listener_lists;
  s_udp_send_pcb = raw_new_ip_type(6,0x11);
  bVar1 = s_udp_send_pcb == 0;
  s_icmp_send_pcb = raw_new_ip_type(6,0x3a);
  if (s_icmp_send_pcb == 0) {
    uVar2 = 0x101;
  }
  else {
    uVar2 = -(uint)bVar1 & 0x101;
  }
  for (; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
    if (uVar2 != 0) goto _L0;
    iVar5 = *piVar3;
    iVar4 = esp_openthread_get_lwip_backbone_netif();
    if (iVar5 == iVar4) {
      iVar5 = *piVar3;
      memcpy(auStack_50,&DAT_00010cec,0x18);
      iVar4 = mld6_joingroup_netif(iVar5,auStack_50);
      uVar2 = 0xffffffff;
      if (iVar4 == 0) {
        memcpy(auStack_38,&_LANCHOR0,0x18);
        iVar4 = mld6_joingroup_netif(iVar5,auStack_38);
        uVar2 = -(uint)(iVar4 != 0);
      }
    }
  }
  if (uVar2 != 0) {
_L0:
    lwip_do_multicast_deinit(0);
  }
  return uVar2;
}

