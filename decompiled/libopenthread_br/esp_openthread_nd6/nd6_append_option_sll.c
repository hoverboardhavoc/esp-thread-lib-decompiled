/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_append_option_sll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nd6_append_option_sll(undefined4 param_1,void *param_2)

{
  undefined2 uStack_18;
  undefined1 auStack_16 [14];
  
  uStack_18 = 0x101;
  memcpy(auStack_16,param_2,6);
  nd6_append_option(param_1,&uStack_18);
  return;
}

