/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatTimeGet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatTimeGet(void)

{
  int iVar1;
  timeval atStack_18 [2];
  
  iVar1 = gettimeofday(atStack_18,(__timezone_ptr_t)0x0);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return (uint)((uint)(atStack_18[0].tv_usec + atStack_18[0].tv_sec * 1000000) <
               (uint)(atStack_18[0].tv_sec * 1000000)) +
         (int)((ulonglong)((longlong)atStack_18[0].tv_sec * 1000000) >> 0x20) +
         (atStack_18[0].tv_usec >> 0x1f);
}

