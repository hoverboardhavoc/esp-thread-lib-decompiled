/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_lock.o -> esp_openthread_lock_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_lock_init(void)

{
  undefined4 uVar1;
  
  if (s_openthread_mutex != 0) {
    return 0x103;
  }
  s_openthread_mutex = xQueueCreateMutex(4);
  if (s_openthread_mutex == 0) {
    uVar1 = 0x101;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

