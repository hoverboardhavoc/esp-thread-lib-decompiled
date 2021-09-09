/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_alarm.o -> esp_openthread_alarm_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_alarm_update(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = otPlatAlarmMicroGetNow();
  if (s_is_ms_running == '\0') {
    uVar6 = 0xffffffff;
    iVar1 = 0x7fffffff;
  }
  else {
    uVar5 = s_alarm_ms_t0 + s_alarm_ms_dt;
    uVar6 = uVar5 * 1000 - iVar2;
    iVar1 = (((uint)(uVar5 < s_alarm_ms_dt) + DAT_000102dc + DAT_000102e4) * 1000 +
            (int)((ulonglong)uVar5 * 1000 >> 0x20)) - (uint)(uVar5 * 1000 < uVar6);
  }
  if (s_is_us_running != '\0') {
    uVar4 = s_alarm_us_t0 + s_alarm_us_dt;
    uVar5 = uVar4 - iVar2;
    iVar2 = ((uint)(uVar4 < s_alarm_us_dt) + DAT_000102ec + DAT_000102f4) - (uint)(uVar4 < uVar5);
    if ((iVar2 < iVar1) || ((iVar1 == iVar2 && (uVar5 < uVar6)))) {
      iVar1 = iVar2;
      uVar6 = uVar5;
    }
  }
  if ((iVar1 < 1) && ((iVar1 != 0 || (uVar6 == 0)))) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    uVar3 = __divdi3(uVar6,iVar1,1000000,0);
    *(undefined4 *)(param_1 + 0x1c) = uVar3;
    uVar3 = __moddi3(uVar6,iVar1,1000000,0);
    *(undefined4 *)(param_1 + 0x20) = uVar3;
  }
  return;
}

