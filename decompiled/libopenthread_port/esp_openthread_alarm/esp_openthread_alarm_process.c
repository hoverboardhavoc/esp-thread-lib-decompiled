/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
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
  int iVar3;
  uint uVar4;
  
  if (s_is_ms_running != '\0') {
    uVar4 = s_alarm_ms_dt + s_alarm_ms_t0;
    bVar1 = uVar4 < s_alarm_ms_t0;
    iVar3 = DAT_000103bc + DAT_000103b4;
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
    uVar4 = s_alarm_us_dt + s_alarm_us_t0;
    bVar1 = uVar4 < s_alarm_us_t0;
    iVar3 = DAT_000103cc + DAT_000103c4;
    uVar2 = otPlatAlarmMicroGetNow();
    if (((uint)bVar1 + iVar3 == 0) && (uVar4 <= uVar2)) {
      s_is_us_running = '\0';
      otPlatAlarmMicroFired(param_1);
    }
  }
  return 0;
}

