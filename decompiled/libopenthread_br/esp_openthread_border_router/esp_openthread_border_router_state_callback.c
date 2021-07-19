/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_state_callback(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x120b0084) == 0) {
    return;
  }
  esp_openthread_get_instance();
  iVar1 = otThreadGetDeviceRole();
  if (iVar1 - 2U < 3) {
    esp_openthread_publish_meshcop_mdns();
  }
  else {
    esp_openthread_remove_meshcop_mdns();
  }
  return;
}

