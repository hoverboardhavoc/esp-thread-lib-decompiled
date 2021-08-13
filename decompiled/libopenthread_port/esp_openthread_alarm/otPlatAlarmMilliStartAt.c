/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMilliStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMilliStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_ms_t0 = param_1;
  DAT_000103bc = 0;
  s_alarm_ms_dt = param_2;
  DAT_000103b4 = 0;
  s_is_ms_running = 1;
  return;
}

