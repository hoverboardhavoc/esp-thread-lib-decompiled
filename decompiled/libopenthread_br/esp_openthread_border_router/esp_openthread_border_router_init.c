/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_border_router_init(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  if (s_backbone_netif == 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Backbone netif not set\n",uVar1,0x10000,
            "esp_openthread_border_router_init",0x8f);
    return 0x103;
  }
  esp_openthread_srp_server_init();
  esp_openthread_get_instance();
  otBorderAgentEphemeralKeySetCallback(esp_openthread_border_ephemeralkey_callback,0);
  iVar2 = esp_openthread_dns_upstream_resolver_init();
  if (iVar2 == 0) {
    iVar2 = esp_openthread_discovery_delegate_init();
    if (iVar2 == 0) {
      esp_openthread_get_instance();
      iVar2 = otSetStateChangedCallback(esp_openthread_border_router_state_callback,0);
      if (iVar2 != 0) {
        uVar1 = esp_log_timestamp();
        esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to install OpenThread state callback\n",uVar1,
                0x10000,"esp_openthread_border_router_init",0x98);
        return -1;
      }
      esp_netif_get_netif_impl(s_backbone_netif);
      iVar2 = esp_openthread_infra_if_init();
      if (iVar2 == 0) {
        iVar2 = esp_openthread_multicast_router_init();
        if (iVar2 == 0) {
          esp_openthread_get_instance();
          otBackboneRouterSetEnabled(1);
          esp_openthread_get_instance();
          iVar2 = otDnssdUpstreamQueryIsEnabled();
          if (iVar2 != 0) {
            return 0;
          }
          esp_openthread_get_instance();
          otDnssdUpstreamQuerySetEnabled(1);
          return 0;
        }
        uVar3 = esp_log_timestamp();
        uVar1 = 0x9e;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize multicast router\n";
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar1 = 0x9c;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize infra interface\n";
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar1 = 0x96;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize discovery delegate\n";
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar1 = 0x94;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize DNS upstream resolver\n";
  }
  esp_log(1,0x10000,pcVar4,uVar3,0x10000,"esp_openthread_border_router_init",uVar1);
  return iVar2;
}

