/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatGetResetReason
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otPlatResetReason otPlatGetResetReason(otInstance *instance)

{
  undefined4 uVar1;
  otPlatResetReason oVar2;
  
  uVar1 = esp_reset_reason();
  switch(uVar1) {
  case 0:
    oVar2 = OT_PLAT_RESET_REASON_UNKNOWN;
    break;
  case 1:
    oVar2 = OT_PLAT_RESET_REASON_POWER_ON;
    break;
  case 2:
    oVar2 = OT_PLAT_RESET_REASON_EXTERNAL;
    break;
  case 3:
    oVar2 = OT_PLAT_RESET_REASON_SOFTWARE;
    break;
  case 4:
    oVar2 = OT_PLAT_RESET_REASON_FAULT;
    break;
  case 5:
    oVar2 = OT_PLAT_RESET_REASON_WATCHDOG;
    break;
  case 6:
    oVar2 = OT_PLAT_RESET_REASON_WATCHDOG;
    break;
  case 7:
    oVar2 = OT_PLAT_RESET_REASON_WATCHDOG;
    break;
  default:
    oVar2 = OT_PLAT_RESET_REASON_OTHER;
  }
  return oVar2;
}

