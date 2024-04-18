/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(uint param_1)

{
  undefined4 uVar1;
  
  if (0x10837 < param_1) {
    uVar1 = 0x102;
    if (param_1 < 0x10839) {
      if (*(int *)(param_1 + 0x30) != -1) {
        sys_untimeout(route_timeout_handler,param_1);
      }
      *(undefined4 *)(param_1 + 0x34) = 0;
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0x102;
}

