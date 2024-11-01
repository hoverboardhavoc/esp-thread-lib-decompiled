/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
  char *pcVar4;
  
  if (s_backbone_netif == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,"E (%lu) %s: %s(%d): Backbone netif not set\n",uVar2,0x10000,
                  "esp_openthread_border_router_init",0x8a);
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
        esp_log_write(1,0x10000,"E (%lu) %s: %s(%d): Failed to install OpenThread state callback\n",
                      uVar2,0x10000,"esp_openthread_border_router_init",0x91);
        return -1;
      }
      esp_netif_get_netif_impl(s_backbone_netif);
      iVar1 = esp_openthread_infra_if_init();
      if (iVar1 == 0) {
        iVar1 = esp_openthread_multicast_router_init();
        if (iVar1 == 0) {
          esp_openthread_get_instance();
          otBackboneRouterSetEnabled(1);
          return 0;
        }
        uVar3 = esp_log_timestamp();
        uVar2 = 0x97;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize multicast router\n";
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0x95;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize infra interface\n";
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0x8f;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize discovery delegate\n";
    }
    esp_log_write(1,0x10000,pcVar4,uVar3,0x10000,"esp_openthread_border_router_init",uVar2);
  }
  return iVar1;
}

