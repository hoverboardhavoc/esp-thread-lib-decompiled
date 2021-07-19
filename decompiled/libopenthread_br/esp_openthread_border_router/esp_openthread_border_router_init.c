/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_router_init(undefined4 param_1)

{
  undefined1 uVar1;
  
  s_backbone_netif = param_1;
  esp_openthread_srp_server_init();
  uVar1 = esp_netif_get_netif_impl_index(param_1);
  netif_get_by_index(uVar1);
  esp_openthread_infra_if_init();
  return;
}

