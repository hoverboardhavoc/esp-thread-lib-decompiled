/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
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
       __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_alarm.c"
                     ,0x2f,"err == 0");
  DAT_000103bc = 0;
  s_alarm_ms_dt = pcVar2;
  DAT_000103b4 = 0;
  s_is_ms_running = 1;
  return s_alarm_ms_t0;
}

