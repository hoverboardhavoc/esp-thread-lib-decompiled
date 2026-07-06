/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> esp_openthread_discovery_delegate_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_discovery_delegate_init(void)

{
  undefined4 uVar1;
  
  uVar1 = esp_openthread_get_instance();
  if (s_mdns_event_fd < 0) {
    s_mdns_event_fd = eventfd(0,0);
    if (-1 < s_mdns_event_fd) {
      otDnssdQuerySetCallbacks(uVar1,handle_discovery_subscribe,0x10000,0);
      uVar1 = esp_openthread_platform_workflow_register
                        (discovery_delegate_update,discovery_delegate_process,"discovery");
      return uVar1;
    }
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to create discovery delegate eventfd\n",uVar1
            ,"esp_openthread_discovery_delegate_init",0x263);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Discovery delegate already initialized\n",uVar1,
            "esp_openthread_discovery_delegate_init",0x260);
    uVar1 = 0x102;
  }
  return uVar1;
}

