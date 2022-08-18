/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_border_router_init(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  
  if (s_backbone_netif == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar3,0x10000,"esp_openthread_border_router_init",100);
    iVar1 = 0x103;
  }
  else {
    esp_openthread_srp_server_init();
    iVar1 = esp_openthread_discovery_delegate_init();
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(esp_openthread_border_router_state_callback,0);
      if (iVar1 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC7,uVar3,0x10000,"esp_openthread_border_router_init",0x69);
        return -1;
      }
      uVar2 = esp_netif_get_netif_impl_index(s_backbone_netif);
      netif_get_by_index(uVar2);
      iVar1 = esp_openthread_infra_if_init();
      if (iVar1 == 0) {
        iVar1 = esp_openthread_multicast_router_init();
        if (iVar1 == 0) {
          return 0;
        }
        uVar4 = esp_log_timestamp();
        uVar3 = 0x70;
        puVar5 = &_LC9;
      }
      else {
        uVar4 = esp_log_timestamp();
        uVar3 = 0x6d;
        puVar5 = &_LC8;
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      uVar3 = 0x67;
      puVar5 = &_LC6;
    }
    esp_log_write(1,0x10000,puVar5,uVar4,0x10000,"esp_openthread_border_router_init",uVar3);
  }
  return iVar1;
}

