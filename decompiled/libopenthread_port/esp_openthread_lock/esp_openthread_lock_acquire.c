/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_lock.o -> esp_openthread_lock_acquire
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint esp_openthread_lock_acquire(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = xQueueTakeMutexRecursive(s_openthread_mutex,param_1);
  if (uVar1 != 0) {
    iVar2 = xQueueTakeMutexRecursive(s_openthread_task_mutex,param_1);
    uVar1 = (uint)(iVar2 != 0);
  }
  return uVar1 & 1;
}

