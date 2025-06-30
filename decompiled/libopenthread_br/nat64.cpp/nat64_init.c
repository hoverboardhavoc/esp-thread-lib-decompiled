/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to initialize nat64 interface\n",uVar2,0x10000,
            0x1d);
  }
  return iVar1;
}

