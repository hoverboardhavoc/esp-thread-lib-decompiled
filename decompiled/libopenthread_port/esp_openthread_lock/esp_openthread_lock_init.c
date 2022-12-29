/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_lock.o -> esp_openthread_lock_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_lock_init(void)

{
  undefined4 uVar1;
  
  uVar1 = 0x103;
  if ((s_openthread_mutex == 0) && (s_openthread_task_mutex == 0)) {
    s_openthread_mutex = xQueueCreateMutex(4);
    s_openthread_task_mutex = xQueueCreateMutex(4);
    uVar1 = 0x101;
    if ((s_openthread_mutex != 0) && (s_openthread_task_mutex != 0)) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

