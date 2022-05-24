/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMilliStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMilliStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_ms_t0 = param_1;
  DAT_000102fc = 0;
  s_alarm_ms_dt = param_2;
  DAT_000102f4 = 0;
  s_is_ms_running = 1;
  return;
}

