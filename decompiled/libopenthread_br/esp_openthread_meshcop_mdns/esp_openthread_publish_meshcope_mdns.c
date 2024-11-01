/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_publish_meshcope_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int esp_openthread_publish_meshcope_mdns(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = esp_openthread_get_instance();
  iVar2 = esp_event_post(_OPENTHREAD_EVENT,0xf,0,0,0);
  if (iVar2 != 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",
                  "E (%lu) %s: Failed to post OpenThread publish meshcop-e service event\n",uVar3,
                  "OPENTHREAD");
  }
  if (s_e_service_published == '\0') {
    uVar1 = otBorderAgentGetUdpPort(uVar1);
    esp_openthread_task_switching_lock_release();
    iVar2 = mdns_service_add(param_1,"_meshcop-e",&_LC16,uVar1,0,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar2 != 0) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to publish meshcop-e mdns service\n",
                    uVar1,"OPENTHREAD","esp_openthread_publish_meshcope_mdns",0xfe);
      return iVar2;
    }
    s_e_service_published = '\x01';
  }
  return 0;
}

