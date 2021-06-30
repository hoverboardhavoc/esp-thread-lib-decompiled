/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMilliStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void otPlatAlarmMilliStartAt(otInstance *aInstance,uint32_t aT0,uint32_t aDt)

{
  s_alarm_ms_t0._0_4_ = aT0;
  s_alarm_ms_t0._4_4_ = 0;
  s_alarm_ms_dt._0_4_ = aDt;
  s_alarm_ms_dt._4_4_ = 0;
  s_is_ms_running = true;
  return;
}

