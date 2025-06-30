/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_route_table.o -> is_better_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool is_better_route(int param_1,int param_2)

{
  if (param_2 != 0) {
    if (*(char *)(param_1 + 0x2c) <= *(char *)(param_2 + 0x2c)) {
      return *(byte *)(param_2 + 0x14) < *(byte *)(param_1 + 0x14) &&
             *(char *)(param_1 + 0x2c) == *(char *)(param_2 + 0x2c);
    }
  }
  return true;
}

