/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(undefined1 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 < s_route_entries) {
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0x102;
    if (param_1 < (undefined1 *)0x10931) {
      if (*(int *)(param_1 + 0x30) != -1) {
        sys_untimeout(route_timeout_handler,param_1);
      }
      *(undefined4 *)(param_1 + 0x34) = 0;
      do {
        if (s_route_entries + 0x1f8 <= param_1) break;
        memcpy(param_1,param_1 + 0x38,0x38);
        piVar1 = (int *)(param_1 + 0x34);
        param_1 = param_1 + 0x38;
      } while (*piVar1 != 0);
      uVar2 = 0;
    }
  }
  return uVar2;
}

