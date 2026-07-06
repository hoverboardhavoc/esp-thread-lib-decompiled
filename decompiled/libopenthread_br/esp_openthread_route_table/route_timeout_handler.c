/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_route_table.o -> route_timeout_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 route_timeout_handler(uint param_1)

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
  if ((0x103bf < param_1) && (param_1 < 0x103c1)) {
    if (*(int *)(param_1 + 0x30) == -1) {
      *(undefined4 *)(param_1 + 0x34) = 0;
      return 0;
    }
    sys_untimeout(route_timeout_handler,param_1);
    *(undefined4 *)(param_1 + 0x34) = 0;
    return 0;
  }
  return 0x102;
}

