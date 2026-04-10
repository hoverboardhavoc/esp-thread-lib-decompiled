/*
 * Last changed at upstream commit 70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * https://github.com/espressif/esp-thread-lib/commit/70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * Upstream date: 2026-04-10 09:53:42 +0000
 * Upstream subject: feat(openthread/lib): update thread-lib for upstream a98813b30
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> otPlatInfraIfSendIcmp6Nd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 otPlatInfraIfSendIcmp6Nd(void *param_1,char *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_70 [40];
  undefined1 auStack_48 [16];
  undefined1 uStack_38;
  undefined1 auStack_34 [16];
  undefined4 uStack_24;
  
  iVar2 = pbuf_alloc(0x36,param_3 + 0x18U & 0xffff,0x280);
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD",
            "E (%lu) %s: %s(%d): Failed to allocate buffer for icmpv6 nd message on backbone netif\n"
            ,uVar3,"br_backbone_netif_create_nd6_msg",0xd6);
  }
  else {
    iVar4 = pbuf_take(param_2,param_3);
    if (iVar4 == 0) {
      *(short *)(iVar2 + 10) = (short)param_3;
      *(short *)(iVar2 + 8) = (short)param_3;
      if (((param_3 != 0) && (*param_2 == -0x7a)) &&
         (iVar4 = esp_openthread_second_netif_nd6_get_state(), iVar4 != 0)) {
        esp_openthread_get_instance();
        iVar4 = otThreadGetDeviceRole();
        uVar3 = 3;
        if (iVar4 != 0) {
          iVar4 = 0x708;
          uVar3 = 0;
        }
        esp_openthread_second_netif_get_prefix(auStack_48);
        memcpy(auStack_34,auStack_48,0x10);
        memcpy(auStack_70,auStack_34,0x14);
        nd6_append_option_rio(iVar2,auStack_70,uStack_38,iVar4,uVar3);
      }
      uStack_24 = 0;
      memcpy(auStack_34,param_1,0x10);
      memcpy(auStack_70,auStack_34,0x14);
      iVar4 = icmp6_raw_send(s_raw_pcb,auStack_70,iVar2,0);
      uVar1 = iVar4 != 0;
      goto _L87;
    }
    uVar3 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD",
            "E (%lu) %s: %s(%d): Failed to create an icmpv6 nd message on backbone netif\n",uVar3,
            "br_backbone_netif_create_nd6_msg",0xd8);
    pbuf_free(iVar2);
  }
  iVar2 = 0;
  uVar1 = 3;
_L87:
  pbuf_free(iVar2);
  return uVar1;
}

