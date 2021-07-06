/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMicroStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMicroStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_us_t0 = param_1;
  DAT_00010374 = 0;
  s_alarm_us_dt = param_2;
  DAT_0001036c = 0;
  s_is_us_running = 1;
  return;
}

