/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_route_table.o -> route_timeout_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 route_timeout_handler(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (0x10624d < *(uint *)(param_1 + 0x30)) {
    uVar3 = *(uint *)(param_1 + 0x30) - 0x10624d;
    *(uint *)(param_1 + 0x30) = uVar3;
    iVar1 = 0x3ffffcc8;
    if (uVar3 < 0x10624e) {
      iVar1 = uVar3 * 1000;
    }
    uVar2 = sys_timeout(iVar1,route_timeout_handler,param_1);
    return uVar2;
  }
  if (param_1 < s_route_entries) {
    return 0x102;
  }
  uVar2 = 0x102;
  if (param_1 < (undefined1 *)0x10809) {
    if (*(int *)(param_1 + 0x30) != -1) {
      sys_untimeout(route_timeout_handler,param_1);
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

