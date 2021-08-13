/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_alarm_update(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = otPlatAlarmMicroGetNow();
  if (s_is_ms_running == '\0') {
    uVar2 = 0xffffffff;
    iVar1 = 0x7fffffff;
  }
  else {
    uVar5 = s_alarm_ms_dt + s_alarm_ms_t0;
    uVar2 = uVar5 * 1000 - iVar3;
    iVar1 = (((uint)(uVar5 < s_alarm_ms_dt) + DAT_000103b4 + DAT_000103bc) * 1000 +
            (int)((ulonglong)uVar5 * 1000 >> 0x20)) - (uint)(uVar5 * 1000 < uVar2);
  }
  if (s_is_us_running != '\0') {
    uVar6 = s_alarm_us_t0 + s_alarm_us_dt;
    uVar5 = uVar6 - iVar3;
    iVar3 = ((uint)(uVar6 < s_alarm_us_dt) + DAT_000103c4 + DAT_000103cc) - (uint)(uVar6 < uVar5);
    if ((iVar3 < iVar1) || ((iVar1 == iVar3 && (uVar5 < uVar2)))) {
      iVar1 = iVar3;
      uVar2 = uVar5;
    }
  }
  if ((iVar1 < 1) && ((iVar1 != 0 || (uVar2 == 0)))) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    uVar4 = __divdi3(uVar2,iVar1,1000000,0);
    *(undefined4 *)(param_1 + 0x1c) = uVar4;
    uVar4 = __moddi3(uVar2,iVar1,1000000,0);
    *(undefined4 *)(param_1 + 0x20) = uVar4;
  }
  return;
}

