/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
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
            "esp_openthread_border_router_init",0x92);
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
                0x10000,"esp_openthread_border_router_init",0x9b);
        return -1;
      }
      esp_netif_get_netif_impl(s_backbone_netif);
      iVar2 = esp_openthread_infra_if_init();
      if (iVar2 == 0) {
        iVar2 = esp_openthread_multicast_router_init();
        if (iVar2 == 0) {
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
        uVar1 = 0xa1;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize multicast router\n";
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar1 = 0x9f;
        pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize infra interface\n";
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar1 = 0x99;
      pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize discovery delegate\n";
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar1 = 0x97;
    pcVar4 = "E (%lu) %s: %s(%d): Failed to initialize DNS upstream resolver\n";
  }
  esp_log(1,0x10000,pcVar4,uVar3,0x10000,"esp_openthread_border_router_init",uVar1);
  return iVar2;
}

