/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_br -> esp_openthread_trel.o -> otPlatTrelUdp6Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void otPlatTrelUdp6Init(void *param_1,undefined2 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_openthread_get_backbone_netif();
  iVar2 = esp_event_handler_register(_OPENTHREAD_EVENT,8,&esp_netif_action_add_ip6_address,uVar1);
  if ((((iVar2 == 0) &&
       (iVar2 = esp_event_handler_register
                          (_OPENTHREAD_EVENT,9,&esp_netif_action_remove_ip6_address,uVar1),
       iVar2 == 0)) &&
      (iVar2 = esp_event_handler_register
                         (_OPENTHREAD_EVENT,10,&esp_netif_action_join_ip6_multicast_group,uVar1),
      iVar2 == 0)) && (iVar2 = add_backbone_trel_address(param_1), iVar2 == 0)) {
    memcpy(s_trel_address,param_1,0x10);
    s_unicast_socket._36_4_ = trel_udp_recv;
    DAT_000103c4 = trel_udp_recv;
    iVar2 = otPlatUdpSocket(s_unicast_socket);
    if (iVar2 == 0) goto _L0;
    do {
      do {
        do {
          __assert_func(0,0,0,0);
_L0:
          iVar2 = otPlatUdpSocket(&s_multicast_socket);
        } while (iVar2 != 0);
        s_multicast_socket = 0;
        DAT_000103a4 = 0;
        DAT_000103a8 = 0;
        DAT_000103ac = 0;
        DAT_000103b0 = param_2;
        iVar2 = otPlatUdpBind(&s_multicast_socket);
      } while (iVar2 != 0);
      memcpy(s_unicast_socket,s_trel_address,0x10);
      s_unicast_socket._16_2_ = param_2;
      iVar2 = otPlatUdpBindToNetif(s_unicast_socket,2);
    } while ((iVar2 != 0) || (iVar2 = otPlatUdpBindToNetif(&s_multicast_socket,2), iVar2 != 0));
    return;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

