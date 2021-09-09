/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  if (s_openthread_mutex == 0) {
    s_openthread_mutex = xQueueCreateMutex(4);
    uVar1 = 0;
    if (s_openthread_mutex == 0) {
      uVar1 = 0x101;
    }
  }
  return uVar1;
}

