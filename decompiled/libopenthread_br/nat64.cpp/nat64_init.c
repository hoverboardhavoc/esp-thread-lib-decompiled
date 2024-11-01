/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
    esp_log_write(1,"NAT64","E (%lu) %s: %s(%d): Failed to initialize nat64 interface\n",uVar2,
                  "NAT64",0x10000,0x1c);
  }
  return iVar1;
}

