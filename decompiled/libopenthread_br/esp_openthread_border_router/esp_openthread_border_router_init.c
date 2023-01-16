/*
 * Last changed at upstream commit 99779af83df3c13d358e1dab7f19699237b1ffdc
 * https://github.com/espressif/esp-thread-lib/commit/99779af83df3c13d358e1dab7f19699237b1ffdc
 * Upstream date: 2023-01-16 10:21:19 +0100
 * Upstream subject: lib: Address lwip thread-safety/core-locking
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_border_router_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if (s_backbone_netif == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar2,0x10000,"esp_openthread_border_router_init",0x65);
    iVar1 = 0x103;
  }
  else {
    esp_openthread_srp_server_init();
    iVar1 = esp_openthread_discovery_delegate_init();
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(esp_openthread_border_router_state_callback,0);
      if (iVar1 != 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC7,uVar2,0x10000,"esp_openthread_border_router_init",0x6a);
        return -1;
      }
      esp_netif_get_netif_impl(s_backbone_netif);
      iVar1 = esp_openthread_infra_if_init();
      if (iVar1 == 0) {
        iVar1 = esp_openthread_multicast_router_init();
        if (iVar1 == 0) {
          return 0;
        }
        uVar3 = esp_log_timestamp();
        uVar2 = 0x70;
        puVar4 = &_LC9;
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0x6e;
        puVar4 = &_LC8;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x68;
      puVar4 = &_LC6;
    }
    esp_log_write(1,0x10000,puVar4,uVar3,0x10000,"esp_openthread_border_router_init",uVar2);
  }
  return iVar1;
}

