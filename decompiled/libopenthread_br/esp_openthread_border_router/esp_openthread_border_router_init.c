/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x52);
    iVar1 = 0x103;
  }
  else {
    esp_openthread_srp_server_init();
    iVar1 = esp_openthread_discovery_delegate_init();
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(0x10000,0);
      if (iVar1 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC5,uVar3,"OPENTHREAD","esp_openthread_border_router_init",
                      0x58);
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
        uVar3 = 0x5e;
        puVar5 = &_LC7;
      }
      else {
        uVar4 = esp_log_timestamp();
        uVar3 = 0x5c;
        puVar5 = &_LC6;
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      uVar3 = 0x55;
      puVar5 = &_LC4;
    }
    esp_log_write(1,"OPENTHREAD",puVar5,uVar4,"OPENTHREAD","esp_openthread_border_router_init",uVar3
                 );
  }
  return iVar1;
}

