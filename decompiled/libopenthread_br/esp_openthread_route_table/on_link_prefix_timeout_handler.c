/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_route_table.o -> on_link_prefix_timeout_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void on_link_prefix_timeout_handler(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((uint)param_1[7] < 0x10624e) {
    *param_1 = 0;
    return;
  }
  uVar2 = param_1[7] - 0x10624d;
  param_1[7] = uVar2;
  iVar1 = 0x3ffffcc8;
  if (uVar2 < 0x10624e) {
    iVar1 = uVar2 * 1000;
  }
  sys_timeout(iVar1,0x10000,param_1);
  return;
}

