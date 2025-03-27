/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to initialize nat64 interface\n",uVar2,"NAT64",
            0x10000,0x1c);
  }
  return iVar1;
}

