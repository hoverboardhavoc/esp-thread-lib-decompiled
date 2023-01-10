/*
 * Last changed at upstream commit 7d57b18006da6e182ddb87698abdced1566f3b56
 * https://github.com/espressif/esp-thread-lib/commit/7d57b18006da6e182ddb87698abdced1566f3b56
 * Upstream date: 2023-01-10 14:40:17 +0800
 * Upstream subject: openthread: add thread_br lib for esp32c2 and esp32c6 * esp_openthread: c558ac0 * ot-repo: 19e1875
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

