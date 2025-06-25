/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> append_rio_to_ra
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void append_rio_to_ra(undefined4 param_1,void *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [44];
  undefined1 auStack_24 [24];
  
  if (param_3 == 0) {
    uVar1 = 0;
    uVar2 = 3;
  }
  else {
    uVar1 = 0x708;
    uVar2 = 0;
  }
  memcpy(auStack_24,param_2,0x10);
  memcpy(auStack_50,auStack_24,0x14);
  nd6_append_option_rio(param_1,auStack_50,*(undefined1 *)((int)param_2 + 0x10),uVar1,uVar2);
  return;
}

