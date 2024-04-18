/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_remove_meshcop_mdns(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (s_service_published != '\0') {
    esp_openthread_task_switching_lock_release();
    iVar1 = mdns_service_remove("_meshcop",&_LC16);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar1 == 0) {
      s_service_published = '\0';
    }
  }
  return iVar1;
}

