/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
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
  undefined4 uVar5;
  int extraout_a1;
  undefined4 extraout_a1_00;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  iVar3 = esp_timer_get_time();
  if (s_is_ms_running == '\0') {
    uVar2 = 0xffffffff;
    iVar1 = 0x7fffffff;
  }
  else {
    uVar6 = s_alarm_ms_t0 + s_alarm_ms_dt;
    uVar2 = uVar6 * 1000 - iVar3;
    iVar1 = ((((uint)(uVar6 < s_alarm_ms_dt) + DAT_00010304 + DAT_0001030c) * 1000 +
             (int)((ulonglong)uVar6 * 1000 >> 0x20)) - extraout_a1) - (uint)(uVar6 * 1000 < uVar2);
  }
  if (s_is_us_running != '\0') {
    uVar7 = s_alarm_us_t0 + s_alarm_us_dt;
    uVar6 = uVar7 - iVar3;
    iVar3 = (((uint)(uVar7 < s_alarm_us_dt) + DAT_0001031c + DAT_00010314) - extraout_a1) -
            (uint)(uVar7 < uVar6);
    if ((iVar3 < iVar1) || ((iVar1 == iVar3 && (uVar6 < uVar2)))) {
      iVar1 = iVar3;
      uVar2 = uVar6;
    }
  }
  if ((iVar1 < 1) && ((iVar1 != 0 || (uVar2 == 0)))) {
    uVar4 = 0;
    uVar8 = 0;
    uVar5 = 0;
  }
  else {
    uVar4 = __divdi3(uVar2,iVar1,1000000,0);
    uVar5 = __moddi3(uVar2,iVar1,1000000,0);
    uVar8 = extraout_a1_00;
  }
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  *(undefined4 *)(param_1 + 0x24) = uVar8;
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  return;
}

