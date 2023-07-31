/*
 * Last changed at upstream commit 6d739fee07d4758fc2fa200b1d3edec99663a930
 * https://github.com/espressif/esp-thread-lib/commit/6d739fee07d4758fc2fa200b1d3edec99663a930
 * Upstream date: 2023-07-31 15:11:37 +0800
 * Upstream subject: feat(br): Fix memory leak and setting mcast forwarding enable
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> multicast_router_init_on_lwip_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void multicast_router_init_on_lwip_task(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [32];
  
  piVar1 = s_netif_listener_lists;
  s_udp_send_pcb = raw_new_ip_type(6,0x11);
  if (s_udp_send_pcb == 0) {
    *param_1 = 0x101;
  }
  s_icmp_send_pcb = raw_new_ip_type(6,0x3a);
  if (s_icmp_send_pcb == 0) {
    *param_1 = 0x101;
  }
  for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
    if (*param_1 != 0) goto _L0;
    iVar3 = *piVar1;
    iVar2 = esp_openthread_get_lwip_backbone_netif();
    if (iVar3 == iVar2) {
      iVar4 = *piVar1;
      memcpy(auStack_50,&DAT_00010cf8,0x18);
      iVar2 = mld6_joingroup_netif(iVar4,auStack_50);
      iVar3 = -1;
      if (iVar2 == 0) {
        memcpy(auStack_38,&_LANCHOR0,0x18);
        iVar2 = mld6_joingroup_netif(iVar4,auStack_38);
        iVar3 = -(uint)(iVar2 != 0);
      }
      *param_1 = iVar3;
    }
  }
  if (*param_1 != 0) {
_L0:
    esp_openthread_multicast_router_deinit();
  }
  xTaskGenericNotify(param_1[1],0,0,2,0);
  return;
}

