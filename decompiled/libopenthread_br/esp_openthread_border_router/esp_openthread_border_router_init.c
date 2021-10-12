/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  
  if (s_backbone_netif == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x38);
    iVar1 = 0x103;
  }
  else {
    esp_openthread_srp_server_init();
    iVar1 = esp_openthread_discovery_delegate_init();
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(0x10000,0);
      if (iVar1 == 0) {
        uVar2 = esp_netif_get_netif_impl_index(s_backbone_netif);
        netif_get_by_index(uVar2);
        iVar1 = esp_openthread_infra_if_init();
        return iVar1;
      }
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x3e
                   );
      iVar1 = -1;
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x3b
                   );
    }
  }
  return iVar1;
}

