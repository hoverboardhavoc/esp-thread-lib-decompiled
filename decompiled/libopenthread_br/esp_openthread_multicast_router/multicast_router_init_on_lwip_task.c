/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> multicast_router_init_on_lwip_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int multicast_router_init_on_lwip_task(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [32];
  
  piVar2 = s_netif_listener_lists;
  s_udp_send_pcb = raw_new_ip_type(6,0x11);
  iVar1 = 0;
  if (s_udp_send_pcb == 0) {
    iVar1 = 0x101;
  }
  s_icmp_send_pcb = raw_new_ip_type(6,0x3a);
  if (s_icmp_send_pcb == 0) {
    iVar1 = 0x101;
  }
  for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
    if (iVar1 != 0) goto _L0;
    iVar4 = *piVar2;
    iVar3 = esp_openthread_get_lwip_backbone_netif();
    if (iVar4 == iVar3) {
      iVar4 = *piVar2;
      memcpy(auStack_50,&DAT_00010d6c,0x18);
      iVar3 = mld6_joingroup_netif(iVar4,auStack_50);
      iVar1 = -1;
      if (iVar3 == 0) {
        memcpy(auStack_38,&_LANCHOR0,0x18);
        iVar1 = mld6_joingroup_netif(iVar4,auStack_38);
        iVar1 = -(uint)(iVar1 != 0);
      }
    }
  }
  if (iVar1 != 0) {
_L0:
    lwip_do_multicast_deinit(0);
  }
  return iVar1;
}

