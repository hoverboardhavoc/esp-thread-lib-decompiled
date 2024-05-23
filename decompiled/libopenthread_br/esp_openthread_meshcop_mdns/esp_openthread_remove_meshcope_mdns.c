/*
 * Last changed at upstream commit 5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * https://github.com/espressif/esp-thread-lib/commit/5ae57e156e4cd2ccd8dc51e90266b16b284e64de
 * Upstream date: 2024-05-23 11:00:44 +0800
 * Upstream subject: feat(br): update border router lib
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcope_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int esp_openthread_remove_meshcope_mdns(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp_event_post(_OPENTHREAD_EVENT,0x10,0,0,0);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
  }
  if (s_e_service_published != '\0') {
    esp_openthread_task_switching_lock_release();
    iVar1 = mdns_service_remove("_meshcop-e",&_LC16);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC42,uVar2,"OPENTHREAD");
      return iVar1;
    }
    s_e_service_published = '\0';
  }
  return 0;
}

