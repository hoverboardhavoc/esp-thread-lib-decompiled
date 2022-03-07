/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> LogIfFail
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::LogIfFail(char const*, otError) */

void ot::Spinel::LogIfFail(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_2 != 0) && (param_2 != 0xe)) {
    uVar1 = otThreadErrorToString(param_2);
    otLogWarnPlat("%s: %s",param_1,uVar1);
    return;
  }
  return;
}

