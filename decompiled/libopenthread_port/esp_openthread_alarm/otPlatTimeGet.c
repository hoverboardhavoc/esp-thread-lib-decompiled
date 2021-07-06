/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatTimeGet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatTimeGet(void)

{
  int iVar1;
  char *pcVar2;
  timeval atStack_18 [2];
  
  iVar1 = gettimeofday(atStack_18,(__timezone_ptr_t)0x0);
  if (iVar1 == 0) {
    return (uint)((uint)(atStack_18[0].tv_usec + atStack_18[0].tv_sec * 1000000) <
                 (uint)(atStack_18[0].tv_sec * 1000000)) +
           (atStack_18[0].tv_sec >> 0x1f) * 1000000 +
           (int)((ulonglong)(uint)atStack_18[0].tv_sec * 1000000 >> 0x20) +
           (atStack_18[0].tv_usec >> 0x1f);
  }
  pcVar2 = "otPlatTimeGet";
  s_alarm_ms_t0 =
       __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_alarm.c"
                     ,0x2d,"err == 0");
  DAT_00010364 = 0;
  s_alarm_ms_dt = pcVar2;
  DAT_0001035c = 0;
  s_is_ms_running = 1;
  return s_alarm_ms_t0;
}

