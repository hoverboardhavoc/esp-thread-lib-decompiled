/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_state_callback(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_24 [20];
  
  if ((param_1 & 0x120b0084) != 0) {
    esp_openthread_get_instance();
    iVar1 = otThreadGetDeviceRole();
    if (iVar1 - 2U < 3) {
      esp_openthread_publish_meshcop_mdns();
    }
    else {
      esp_openthread_remove_meshcop_mdns();
    }
  }
  esp_openthread_get_instance();
  iVar1 = otBorderRoutingGetNat64Prefix(auStack_24);
  if ((iVar1 == 0) && (s_nat64_initialized == '\0')) {
    iVar1 = nat64_init();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,0x10000,&_LC1,uVar2,0x10000);
      s_nat64_initialized = '\x01';
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar2,0x10000);
    }
  }
  if ((param_1 & 0x2000000) == 0) {
    return;
  }
  esp_openthread_get_instance();
  uVar3 = otBackboneRouterGetState();
  if (uVar3 < 2) {
    esp_openthread_multicast_forwarding_set_enabled(0);
    return;
  }
  if (uVar3 != 2) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC3,uVar2,0x10000);
    return;
  }
  esp_openthread_multicast_forwarding_set_enabled(1);
  tcpip_callback(multicast_probe_task,0);
  return;
}

