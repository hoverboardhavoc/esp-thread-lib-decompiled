/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_append_option_pio
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nd6_append_option_pio
               (undefined4 param_1,void *param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_20 [24];
  
  uStack_30 = 0x403;
  uStack_2e = param_3;
  memcpy(auStack_20,param_2,0x10);
  memset(&uStack_2d,0,0xd);
  uStack_2d = 0xc0;
  uStack_2c = __bswapsi2(param_4);
  uStack_28 = __bswapsi2(param_5);
  nd6_append_option(param_1,&uStack_30,0x20);
  return;
}

