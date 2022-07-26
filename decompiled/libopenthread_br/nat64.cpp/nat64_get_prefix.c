/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64.cpp.o -> nat64_get_prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * nat64_get_prefix(void *param_1)

{
  int iVar1;
  undefined1 auStack_24 [16];
  byte bStack_14;
  
  memset(param_1,0,0x18);
  esp_openthread_get_instance();
  iVar1 = otBorderRoutingGetNat64Prefix(auStack_24);
  if (iVar1 == 0) {
    if ((bStack_14 & 7) != 0) {
      __assert_func(0,0,0);
    }
    memcpy(param_1,auStack_24,0x10);
    *(byte *)((int)param_1 + 0x14) = bStack_14;
  }
  return param_1;
}

