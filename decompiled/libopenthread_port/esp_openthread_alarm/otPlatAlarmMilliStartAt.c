/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatAlarmMilliStartAt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatAlarmMilliStartAt(undefined4 param_1,undefined4 param_2)

{
  s_alarm_ms_t0 = param_1;
  DAT_000102e4 = 0;
  s_alarm_ms_dt = param_2;
  DAT_000102dc = 0;
  s_is_ms_running = 1;
  return;
}

