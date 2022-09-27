/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_alarm_process(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  uint extraout_a1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (s_is_ms_running != '\0') {
    uVar4 = s_alarm_ms_dt + s_alarm_ms_t0;
    bVar1 = uVar4 < s_alarm_ms_t0;
    iVar3 = DAT_00010314 + DAT_0001031c;
    uVar2 = otPlatAlarmMilliGetNow();
    if (((uint)bVar1 + iVar3 == 0) && (uVar4 <= uVar2)) {
      s_is_ms_running = '\0';
      iVar3 = otPlatDiagModeGet();
      if (iVar3 == 0) {
        otPlatAlarmMilliFired(param_1);
      }
      else {
        otPlatDiagAlarmFired(param_1);
      }
    }
  }
  if (s_is_us_running != '\0') {
    uVar5 = s_alarm_us_dt + s_alarm_us_t0;
    uVar2 = (uint)(uVar5 < s_alarm_us_t0) + DAT_00010324 + DAT_0001032c;
    uVar4 = esp_timer_get_time();
    if ((uVar2 <= extraout_a1) && ((uVar2 != extraout_a1 || (uVar5 <= uVar4)))) {
      s_is_us_running = '\0';
      otPlatAlarmMicroFired(param_1);
    }
  }
  return 0;
}

