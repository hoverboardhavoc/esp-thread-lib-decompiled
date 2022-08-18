/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
    if (param_1 < (undefined1 *)0x10925) {
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

