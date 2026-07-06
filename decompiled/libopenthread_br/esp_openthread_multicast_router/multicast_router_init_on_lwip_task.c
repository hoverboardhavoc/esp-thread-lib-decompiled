/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
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
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
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
    if (uVar2 != 0) goto _L47;
    iVar5 = *piVar3;
    iVar4 = esp_openthread_get_lwip_backbone_netif();
    if (iVar5 == iVar4) {
      iVar5 = *piVar3;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_40 = 0;
      local_50 = 0x2ff;
      uStack_44 = 0x2000000;
      uStack_3c = 6;
      iVar4 = mld6_joingroup_netif(iVar5,&local_50);
      uVar2 = 0xffffffff;
      if (iVar4 == 0) {
        uStack_34 = 0;
        uStack_30 = 0;
        uStack_28 = 0;
        uStack_38 = 0x2ff;
        uStack_2c = 0x16000000;
        uStack_24 = 6;
        iVar4 = mld6_joingroup_netif(iVar5,&uStack_38);
        uVar2 = -(uint)(iVar4 != 0);
      }
    }
  }
  if (uVar2 != 0) {
_L47:
    lwip_do_multicast_deinit(0);
  }
  return uVar2;
}

