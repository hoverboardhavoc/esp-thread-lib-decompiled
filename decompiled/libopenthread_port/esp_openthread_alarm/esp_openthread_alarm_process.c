/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_alarm_process(otInstance *aInstance)

{
  bool bVar1;
  uint32_t uVar2;
  int iVar3;
  uint uVar4;
  
  if (s_is_ms_running) {
    uVar4 = (int)s_alarm_ms_dt + (uint)s_alarm_ms_t0;
    bVar1 = uVar4 < (uint)s_alarm_ms_t0;
    iVar3 = s_alarm_ms_t0._4_4_ + s_alarm_ms_dt._4_4_;
    uVar2 = otPlatAlarmMilliGetNow();
    if (((uint)bVar1 + iVar3 == 0) && (uVar4 <= uVar2)) {
      s_is_ms_running = false;
      iVar3 = otPlatDiagModeGet();
      if (iVar3 == 0) {
        otPlatAlarmMilliFired(aInstance);
      }
      else {
        otPlatDiagAlarmFired(aInstance);
      }
    }
  }
  if (s_is_us_running != false) {
    uVar4 = (int)s_alarm_us_dt + (uint)s_alarm_us_t0;
    bVar1 = uVar4 < (uint)s_alarm_us_t0;
    iVar3 = s_alarm_us_t0._4_4_ + s_alarm_us_dt._4_4_;
    uVar2 = otPlatAlarmMicroGetNow();
    if (((uint)bVar1 + iVar3 == 0) && (uVar4 <= uVar2)) {
      s_is_us_running = false;
      otPlatAlarmMicroFired(aInstance);
    }
  }
  return;
}

