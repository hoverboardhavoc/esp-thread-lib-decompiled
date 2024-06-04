/*
 * Last changed at upstream commit 34d698a274940730901b934caa023a3281aca53e
 * https://github.com/espressif/esp-thread-lib/commit/34d698a274940730901b934caa023a3281aca53e
 * Upstream date: 2024-06-04 12:02:17 +0800
 * Upstream subject: feat(openthread): update br lib
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(uint param_1)

{
  undefined4 uVar1;
  
  if (0x103c3 < param_1) {
    uVar1 = 0x102;
    if (param_1 < 0x103c5) {
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

