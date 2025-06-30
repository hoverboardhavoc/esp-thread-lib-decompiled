/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_append_option_rio
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nd6_append_option_rio
               (undefined4 param_1,void *param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined2 uStack_38;
  undefined1 uStack_36;
  byte bStack_35;
  undefined4 uStack_34;
  undefined1 auStack_30 [28];
  
  memset(&bStack_35,0,0x15);
  uStack_38 = 0x218;
  uStack_36 = (undefined1)param_3;
  memcpy(auStack_30,param_2,param_3 >> 3);
  bStack_35 = bStack_35 & 0xe7 | (byte)((param_5 & 3) << 3);
  uStack_34 = __bswapsi2(param_4);
  nd6_append_option(param_1,&uStack_38,(param_3 >> 3) + 8);
  return;
}

