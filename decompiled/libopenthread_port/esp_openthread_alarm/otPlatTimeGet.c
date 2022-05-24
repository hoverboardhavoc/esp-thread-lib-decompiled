/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatTimeGet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatTimeGet(void)

{
  int iVar1;
  timeval local_20;
  int iStack_18;
  
  iVar1 = gettimeofday(&local_20,(__timezone_ptr_t)0x0);
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return (uint)((uint)(iStack_18 + local_20.tv_sec * 1000000) < (uint)(local_20.tv_sec * 1000000)) +
         local_20.tv_usec * 1000000 + (int)((ulonglong)(uint)local_20.tv_sec * 1000000 >> 0x20) +
         (iStack_18 >> 0x1f);
}

