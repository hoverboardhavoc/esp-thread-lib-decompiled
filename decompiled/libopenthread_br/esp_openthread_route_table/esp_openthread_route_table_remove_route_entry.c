/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
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
    return 0x102;
  }
  uVar2 = 0x102;
  if (param_1 < s_route_entries + 1) {
    if (*(int *)(param_1 + 0x30) != -1) {
      sys_untimeout(route_timeout_handler,param_1);
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    do {
      if (s_route_entries <= param_1) break;
      memcpy(param_1,param_1 + 0x38,0x38);
      piVar1 = (int *)(param_1 + 0x34);
      param_1 = param_1 + 0x38;
    } while (*piVar1 != 0);
    uVar2 = 0;
  }
  return uVar2;
}

