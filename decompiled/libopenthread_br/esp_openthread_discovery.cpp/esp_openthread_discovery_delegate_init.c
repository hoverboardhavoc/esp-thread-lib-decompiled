/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
              uVar1,"esp_openthread_discovery_delegate_init",0x1fb);
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
              ,"esp_openthread_discovery_delegate_init",0x1fd);
      uVar1 = 0x101;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Discovery delegate already initialized\n",uVar1,
            "esp_openthread_discovery_delegate_init",0x1f8);
    uVar1 = 0x102;
  }
  return uVar1;
}

