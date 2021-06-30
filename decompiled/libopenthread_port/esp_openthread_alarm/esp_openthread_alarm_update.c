/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_alarm_update(esp_openthread_mainloop_context_t *mainloop)

{
  int iVar1;
  uint uVar2;
  uint32_t uVar3;
  time_t tVar4;
  suseconds_t sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar3 = otPlatAlarmMicroGetNow();
  if (s_is_ms_running == false) {
    uVar2 = 0xffffffff;
    iVar1 = 0x7fffffff;
  }
  else {
    uVar6 = (uint)s_alarm_ms_dt + (int)s_alarm_ms_t0;
    uVar2 = uVar6 * 1000 - uVar3;
    iVar1 = (((uint)(uVar6 < (uint)s_alarm_ms_dt) + s_alarm_ms_dt._4_4_ + s_alarm_ms_t0._4_4_) *
             1000 + (int)((ulonglong)uVar6 * 1000 >> 0x20)) - (uint)(uVar6 * 1000 < uVar2);
  }
  if (s_is_us_running != false) {
    uVar7 = (int)s_alarm_us_t0 + (uint)s_alarm_us_dt;
    uVar6 = uVar7 - uVar3;
    iVar8 = ((uint)(uVar7 < (uint)s_alarm_us_dt) + s_alarm_us_dt._4_4_ + s_alarm_us_t0._4_4_) -
            (uint)(uVar7 < uVar6);
    if ((iVar8 < iVar1) || ((iVar1 == iVar8 && (uVar6 < uVar2)))) {
      iVar1 = iVar8;
      uVar2 = uVar6;
    }
  }
  if ((iVar1 < 1) && ((iVar1 != 0 || (uVar2 == 0)))) {
    (mainloop->timeout).tv_sec = 0;
    (mainloop->timeout).tv_usec = 0;
  }
  else {
    tVar4 = __divdi3(uVar2,iVar1,1000000,0);
    (mainloop->timeout).tv_sec = tVar4;
    sVar5 = __moddi3(uVar2,iVar1,1000000,0);
    (mainloop->timeout).tv_usec = sVar5;
  }
  return;
}

