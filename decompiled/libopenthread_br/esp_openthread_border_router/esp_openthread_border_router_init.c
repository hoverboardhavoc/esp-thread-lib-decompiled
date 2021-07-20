/*
 * Last changed at upstream commit 4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * https://github.com/espressif/esp-thread-lib/commit/4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * Upstream date: 2021-07-20 11:34:17 +0800
 * Upstream subject: openthread: remove build dependency on border router in port library
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_border_router_init(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  s_backbone_netif = param_1;
  esp_openthread_srp_server_init();
  esp_openthread_get_instance();
  iVar2 = otSetStateChangedCallback(0x10000,0);
  if (iVar2 == 0) {
    uVar1 = esp_netif_get_netif_impl_index(param_1);
    netif_get_by_index(uVar1);
    uVar3 = esp_openthread_infra_if_init();
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD","esp_openthread_border_router_init",0x37);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

