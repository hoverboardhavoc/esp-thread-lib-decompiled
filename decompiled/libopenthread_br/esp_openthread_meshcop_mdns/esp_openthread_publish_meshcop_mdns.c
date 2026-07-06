/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_publish_meshcop_mdns(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = 0;
  if (s_service_published == '\0') {
    uVar2 = esp_openthread_get_instance();
    uVar3 = otBorderAgentGetUdpPort();
    esp_openthread_task_switching_lock_release();
    iVar1 = mdns_service_add(param_1,"_meshcop",&_LC3,uVar3,0,0);
    if (iVar1 == 0) {
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      s_service_published = '\x01';
      otBorderAgentSetMeshCoPServiceChangedCallback(uVar2,update_meshcop_mdns,0);
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to publish meshcop mdns service\n",uVar2,
              "esp_openthread_publish_meshcop_mdns",0x4d);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
    }
  }
  return iVar1;
}

