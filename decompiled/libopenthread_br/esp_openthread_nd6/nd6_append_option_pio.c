/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
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
  uint uStack_28;
  undefined3 uStack_24;
  undefined1 uStack_21;
  undefined1 auStack_20 [24];
  
  uStack_30 = 0x403;
  uStack_2e = param_3;
  memcpy(auStack_20,param_2,0x10);
  uStack_2d = 0xc0;
  uStack_28 = uStack_28 & 0xffffff;
  uStack_24 = 0;
  uStack_21 = 0;
  uStack_2c = __bswapsi2(param_4);
  uStack_28 = __bswapsi2(param_5);
  nd6_append_option(param_1,&uStack_30,0x20);
  return;
}

