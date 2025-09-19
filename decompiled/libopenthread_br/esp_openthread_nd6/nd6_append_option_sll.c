/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_append_option_sll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nd6_append_option_sll(undefined4 *param_1)

{
  undefined2 uStack_18;
  undefined4 uStack_16;
  undefined2 uStack_12;
  
  uStack_18 = 0x101;
  uStack_16 = *param_1;
  uStack_12 = *(undefined2 *)(param_1 + 1);
  nd6_append_option(&uStack_18);
  return;
}

