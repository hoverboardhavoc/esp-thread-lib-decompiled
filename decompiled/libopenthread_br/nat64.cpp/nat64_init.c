/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
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
  if (iVar1 == 0) {
    esp_openthread_get_instance();
    otNat64SetEnabled(1);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"NAT64",&_LC2,uVar2,"NAT64",0x10000,0x19);
  }
  return iVar1;
}

