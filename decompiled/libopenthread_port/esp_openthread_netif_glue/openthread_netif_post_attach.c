/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_post_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t openthread_netif_post_attach(esp_netif_t *esp_netif,void *args)

{
  int iVar1;
  esp_err_t eVar2;
  esp_openthread_netif_glue_t *local_20;
  esp_netif_driver_ifconfig_t driver_ifconfig;
  
  *(esp_netif_t **)((int)args + 4) = esp_netif;
  driver_ifconfig.transmit = (_func_esp_err_t_void_ptr_void_ptr_size_t *)0x0;
  driver_ifconfig.transmit_wrap = (_func_esp_err_t_void_ptr_void_ptr_size_t_void_ptr *)0x0;
  local_20 = &s_openthread_netif_glue;
  driver_ifconfig.handle = openthread_netif_transmit;
  iVar1 = esp_netif_set_driver_config(&local_20);
  if (iVar1 == 0) {
    otLogInfo(0xc,"-PLAT----: ","OpenThread attached to netif");
    eVar2 = register_openthread_event_handlers(esp_netif);
    s_openthread_netif = esp_netif;
    if (eVar2 != 0) {
      return eVar2;
    }
  }
  else {
    _esp_error_check_failed
              ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
               ,0x109,"openthread_netif_post_attach",
               "esp_netif_set_driver_config(esp_netif, &driver_ifconfig)");
  }
  eVar2 = esp_event_post(OPENTHREAD_EVENT,0,0,0,0);
  return eVar2;
}

