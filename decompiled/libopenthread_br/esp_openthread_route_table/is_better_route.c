/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_route_table.o -> is_better_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool is_better_route(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 != 0) {
    bVar1 = true;
    if ((*(char *)(param_1 + 0x2c) <= *(char *)(param_2 + 0x2c)) &&
       (bVar1 = false, *(char *)(param_1 + 0x2c) == *(char *)(param_2 + 0x2c))) {
      bVar1 = *(byte *)(param_2 + 0x14) < *(byte *)(param_1 + 0x14);
    }
    return bVar1;
  }
  return true;
}

