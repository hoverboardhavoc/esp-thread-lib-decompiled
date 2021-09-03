/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_border_router_init(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  s_backbone_netif = param_1;
  esp_openthread_srp_server_init();
  iVar2 = esp_openthread_discovery_delegate_init();
  if (iVar2 == 0) {
    esp_openthread_get_instance();
    iVar2 = otSetStateChangedCallback(0x10000,0);
    if (iVar2 == 0) {
      uVar1 = esp_netif_get_netif_impl_index(param_1);
      netif_get_by_index(uVar1);
      iVar2 = esp_openthread_infra_if_init();
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x3a
                   );
      iVar2 = -1;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x37);
  }
  return iVar2;
}

