/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_post_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void openthread_netif_post_attach(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *local_20;
  code *pcStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  *(undefined4 *)(param_2 + 4) = param_1;
  uStack_18 = 0;
  uStack_14 = 0;
  local_20 = &s_openthread_netif_glue;
  pcStack_1c = openthread_netif_transmit;
  iVar1 = esp_netif_set_driver_config(&local_20);
  if (iVar1 == 0) {
    otLogInfo(0xc,"-PLAT----: ","OpenThread attached to netif");
    iVar1 = register_openthread_event_handlers(param_1);
    s_openthread_netif = param_1;
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    _esp_error_check_failed
              ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
               ,0x101,"openthread_netif_post_attach",
               "esp_netif_set_driver_config(esp_netif, &driver_ifconfig)");
  }
  esp_event_post(OPENTHREAD_EVENT,0,0,0,0);
  return;
}

