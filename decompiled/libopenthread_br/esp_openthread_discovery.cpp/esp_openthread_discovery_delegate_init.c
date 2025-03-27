/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
    if (s_mdns_event_fd < 0) {
      uVar1 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to create discovery delegate eventfd\n",
              uVar1,"OPENTHREAD","esp_openthread_discovery_delegate_init",0x1f9);
      uVar1 = 0xffffffff;
    }
    else {
      s_mdns_result_queue = xQueueGenericCreate(10,4,0);
      if (s_mdns_result_queue != 0) {
        otDnssdQuerySetCallbacks(uVar1,handle_discovery_subscribe,0x10000,0);
        uVar1 = esp_openthread_platform_workflow_register
                          (discovery_delegate_update,discovery_delegate_process,"discovery");
        return uVar1;
      }
      uVar1 = esp_log_timestamp();
      esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to create discovery delegate queue\n",uVar1
              ,"OPENTHREAD","esp_openthread_discovery_delegate_init",0x1fb);
      uVar1 = 0x101;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Discovery delegate already initialized\n",uVar1,
            "OPENTHREAD","esp_openthread_discovery_delegate_init",0x1f6);
    uVar1 = 0x102;
  }
  return uVar1;
}

