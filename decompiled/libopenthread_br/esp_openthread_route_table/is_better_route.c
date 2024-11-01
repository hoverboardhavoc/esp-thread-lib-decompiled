/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
 * Source: libopenthread_br -> esp_openthread_route_table.o -> is_better_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool is_better_route(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
    if (param_1 != 0) {
      bVar1 = true;
      if ((*(char *)(param_1 + 0x2c) <= *(char *)(param_2 + 0x2c)) &&
         (bVar1 = false, *(char *)(param_1 + 0x2c) == *(char *)(param_2 + 0x2c))) {
        return *(byte *)(param_2 + 0x14) < *(byte *)(param_1 + 0x14);
      }
    }
  }
  return bVar1;
}

