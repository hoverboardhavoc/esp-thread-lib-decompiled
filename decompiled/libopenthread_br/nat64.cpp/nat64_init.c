/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64.cpp.o -> nat64_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nat64_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = nat64_netif_init();
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"NAT64",&_LC2,uVar2,"NAT64",0x10000,0x18);
  }
  return iVar1;
}

