/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
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
    esp_log_write(1,0x10000,&_L0,uVar2,0x10000,"esp_openthread_border_router_init",0x74);
    iVar1 = 0x103;
  }
  else {
    esp_openthread_srp_server_init();
    esp_openthread_get_instance();
    otBorderAgentSetEphemeralKeyCallback(esp_openthread_border_ephemeralkey_callback,0);
    iVar1 = esp_openthread_discovery_delegate_init();
    if (iVar1 == 0) {
      esp_openthread_get_instance();
      iVar1 = otSetStateChangedCallback(esp_openthread_border_router_state_callback,0);
      if (iVar1 != 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,0x10000,&_LC7,uVar2,0x10000,"esp_openthread_border_router_init",0x7b);
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
        uVar2 = 0x81;
        puVar4 = &_LC9;
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0x7f;
        puVar4 = &_LC8;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x79;
      puVar4 = &_LC6;
    }
    esp_log_write(1,0x10000,puVar4,uVar3,0x10000,"esp_openthread_border_router_init",uVar2);
  }
  return iVar1;
}

