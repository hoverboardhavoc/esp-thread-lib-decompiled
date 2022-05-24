/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMicroStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMicroStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_us_t0 = param_1;
  DAT_0001030c = 0;
  s_alarm_us_dt = param_2;
  DAT_00010304 = 0;
  s_is_us_running = 1;
  return;
}

