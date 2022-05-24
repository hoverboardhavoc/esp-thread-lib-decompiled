/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_state_callback(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
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
  if ((param_1 & 0x2000000) == 0) {
    return;
  }
  esp_openthread_get_instance();
  uVar2 = otBackboneRouterGetState();
  if (uVar2 < 2) {
    esp_openthread_multicast_forwarding_set_enabled(0);
    return;
  }
  if (uVar2 != 2) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000);
    return;
  }
  esp_openthread_multicast_forwarding_set_enabled(1);
  tcpip_callback(multicast_probe_task,0);
  return;
}

