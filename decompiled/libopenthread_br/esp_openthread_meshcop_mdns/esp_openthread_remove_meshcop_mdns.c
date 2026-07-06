/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_remove_meshcop_mdns(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (s_service_published != '\0') {
    uVar2 = esp_openthread_get_instance();
    esp_openthread_task_switching_lock_release();
    iVar1 = mdns_service_remove("_meshcop",&_LC3);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar1 == 0) {
      s_service_published = '\0';
      otBorderAgentSetMeshCoPServiceChangedCallback(uVar2,0,0);
    }
  }
  return iVar1;
}

