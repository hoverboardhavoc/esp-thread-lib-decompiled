/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(char *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 < s_route_entries) {
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0x102;
    if (param_1 < "PENTHREAD") {
      sys_untimeout(route_timeout_handler,param_1);
      param_1[0x34] = '\0';
      param_1[0x35] = '\0';
      param_1[0x36] = '\0';
      param_1[0x37] = '\0';
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

