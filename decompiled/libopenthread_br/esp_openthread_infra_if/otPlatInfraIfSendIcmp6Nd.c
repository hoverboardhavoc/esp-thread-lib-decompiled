/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> otPlatInfraIfSendIcmp6Nd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatInfraIfSendIcmp6Nd(void *param_1,char *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_70 [40];
  undefined1 auStack_48 [16];
  undefined1 uStack_38;
  undefined1 auStack_34 [16];
  undefined4 uStack_24;
  
  iVar1 = pbuf_alloc(0x36,param_3 + 0x18U & 0xffff,0x280);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD",
            "E (%lu) %s: %s(%d): Failed to allocate buffer for icmpv6 nd message on backbone netif\n"
            ,uVar2,"br_backbone_netif_create_nd6_msg",0xcb);
  }
  else {
    iVar3 = pbuf_take(param_2,param_3);
    if (iVar3 == 0) {
      *(short *)(iVar1 + 10) = (short)param_3;
      *(short *)(iVar1 + 8) = (short)param_3;
      if (((param_3 != 0) && (*param_2 == -0x7a)) &&
         (iVar3 = esp_openthread_second_netif_nd6_get_state(), iVar3 != 0)) {
        esp_openthread_get_instance();
        iVar3 = otThreadGetDeviceRole();
        uVar2 = 3;
        if (iVar3 != 0) {
          iVar3 = 0x708;
          uVar2 = 0;
        }
        esp_openthread_second_netif_get_prefix(auStack_48);
        memcpy(auStack_34,auStack_48,0x10);
        memcpy(auStack_70,auStack_34,0x14);
        nd6_append_option_rio(iVar1,auStack_70,uStack_38,iVar3,uVar2);
      }
      uStack_24 = 0;
      memcpy(auStack_34,param_1,0x10);
      memcpy(auStack_70,auStack_34,0x14);
      uVar2 = icmp6_raw_send(s_raw_pcb,auStack_70,iVar1,0);
      pbuf_free(iVar1);
      return uVar2;
    }
    uVar2 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD",
            "E (%lu) %s: %s(%d): Failed to create an icmpv6 nd message on backbone netif\n",uVar2,
            "br_backbone_netif_create_nd6_msg",0xcd);
    pbuf_free(iVar1);
  }
  return 3;
}

