/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_alarm_process(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (s_is_ms_running != '\0') {
    uVar4 = s_alarm_ms_dt + s_alarm_ms_t0;
    bVar1 = uVar4 < s_alarm_ms_t0;
    iVar2 = DAT_000102e4 + DAT_000102dc;
    uVar3 = otPlatAlarmMilliGetNow();
    if ((iVar2 + (uint)bVar1 == 0) && (uVar4 <= uVar3)) {
      s_is_ms_running = '\0';
      otPlatAlarmMilliFired(param_1);
    }
  }
  if (s_is_us_running != '\0') {
    uVar4 = s_alarm_us_dt + s_alarm_us_t0;
    bVar1 = uVar4 < s_alarm_us_t0;
    iVar2 = DAT_000102f4 + DAT_000102ec;
    uVar3 = otPlatAlarmMicroGetNow();
    if ((iVar2 + (uint)bVar1 == 0) && (uVar4 <= uVar3)) {
      s_is_us_running = '\0';
      otPlatAlarmMicroFired(param_1);
    }
  }
  return 0;
}

