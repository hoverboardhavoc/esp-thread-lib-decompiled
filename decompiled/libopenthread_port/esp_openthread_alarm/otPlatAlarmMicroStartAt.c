/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMicroStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMicroStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_us_t0 = param_1;
  DAT_000103ac = 0;
  s_alarm_us_dt = param_2;
  DAT_000103a4 = 0;
  s_is_us_running = 1;
  return;
}

