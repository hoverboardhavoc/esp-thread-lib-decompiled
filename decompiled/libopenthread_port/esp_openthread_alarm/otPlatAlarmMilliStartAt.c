/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMilliStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMilliStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_ms_t0 = param_1;
  DAT_0001030c = 0;
  s_alarm_ms_dt = param_2;
  DAT_00010304 = 0;
  s_is_ms_running = 1;
  return;
}

