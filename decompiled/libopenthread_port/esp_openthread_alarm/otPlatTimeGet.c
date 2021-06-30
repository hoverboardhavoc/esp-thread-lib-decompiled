/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_alarm.o -> otPlatTimeGet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint64_t otPlatTimeGet(void)

{
  int iVar1;
  undefined4 extraout_a1;
  char *pcVar2;
  uint64_t extraout_fa0;
  uint64_t uVar3;
  undefined1 auStack_18 [4];
  timeval tv_now;
  
  iVar1 = gettimeofday((timeval *)auStack_18,(__timezone_ptr_t)0x0);
  if (iVar1 == 0) {
    return extraout_fa0;
  }
  pcVar2 = "otPlatTimeGet";
  uVar3 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_alarm.c"
                        ,0x2d,"err == 0");
  s_alarm_ms_t0._0_4_ = extraout_a1;
  s_alarm_ms_t0._4_4_ = 0;
  s_alarm_ms_dt._0_4_ = pcVar2;
  s_alarm_ms_dt._4_4_ = 0;
  s_is_ms_running = true;
  return uVar3;
}

