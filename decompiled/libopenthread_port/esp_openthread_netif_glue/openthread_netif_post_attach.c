/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_post_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void openthread_netif_post_attach(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
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
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC23,uVar2,"OPENTHREAD");
    iVar1 = register_openthread_event_handlers(param_1);
    s_openthread_netif = param_1;
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    _esp_error_check_failed
              ("/home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
               ,0x105,"openthread_netif_post_attach",
               "esp_netif_set_driver_config(esp_netif, &driver_ifconfig)");
  }
  esp_event_post(OPENTHREAD_EVENT,0,0,0,0);
  return;
}

