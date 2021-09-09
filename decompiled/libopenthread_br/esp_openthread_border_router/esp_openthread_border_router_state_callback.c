/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
    return;
  }
  esp_openthread_remove_meshcop_mdns();
  return;
}

