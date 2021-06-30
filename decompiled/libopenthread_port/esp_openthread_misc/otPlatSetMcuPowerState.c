/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_misc.o -> otPlatSetMcuPowerState
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatSetMcuPowerState(otInstance *instance,otPlatMcuPowerState state)

{
  if (OT_PLAT_MCU_POWER_STATE_LOW_POWER < state) {
    return OT_ERROR_FAILED;
  }
  s_mcu_power_state = state;
  return OT_ERROR_NONE;
}

