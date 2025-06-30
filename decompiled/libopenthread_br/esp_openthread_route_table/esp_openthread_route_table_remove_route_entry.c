/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(uint param_1)

{
  if ((0x103c3 < param_1) && (param_1 < 0x103c5)) {
    if (*(int *)(param_1 + 0x30) != -1) {
      sys_untimeout(route_timeout_handler,param_1);
      *(undefined4 *)(param_1 + 0x34) = 0;
      return 0;
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    return 0;
  }
  return 0x102;
}

