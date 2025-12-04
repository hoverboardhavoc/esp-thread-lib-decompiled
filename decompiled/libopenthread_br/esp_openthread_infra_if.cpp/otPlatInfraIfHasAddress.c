/*
 * Last changed at upstream commit 66e81acb8df80dbc52a2b0841a8ae3153557e131
 * https://github.com/espressif/esp-thread-lib/commit/66e81acb8df80dbc52a2b0841a8ae3153557e131
 * Upstream date: 2025-12-04 07:38:20 +0000
 * Upstream subject: fix(openthread): resolve deadlock issues due to switching_lock
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> otPlatInfraIfHasAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatInfraIfHasAddress(void *param_1)

{
  int iVar1;
  undefined1 auStack_24 [28];
  
  memcpy(auStack_24,param_1,0x10);
  esp_openthread_task_switching_lock_release();
  iVar1 = esp_netif_tcpip_exec(infra_if_is_self_address,auStack_24);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return iVar1 == 0;
}

