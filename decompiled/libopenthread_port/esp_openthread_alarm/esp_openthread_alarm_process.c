/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_alarm_process(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (s_is_ms_running != '\0') {
    uVar4 = s_alarm_ms_dt + s_alarm_ms_t0;
    bVar1 = uVar4 < s_alarm_ms_t0;
    iVar3 = DAT_00010364 + DAT_0001035c;
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
    iVar3 = DAT_00010374 + DAT_0001036c;
    uVar2 = otPlatAlarmMicroGetNow();
    if (((uint)bVar1 + iVar3 == 0) && (uVar4 <= uVar2)) {
      s_is_us_running = '\0';
      otPlatAlarmMicroFired(param_1);
    }
  }
  return;
}

