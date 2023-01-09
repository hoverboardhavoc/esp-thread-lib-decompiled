/*
 * Last changed at upstream commit af5d67ed3acb06cac9e06986b08781b93bd6dade
 * https://github.com/espressif/esp-thread-lib/commit/af5d67ed3acb06cac9e06986b08781b93bd6dade
 * Upstream date: 2023-01-09 11:37:28 +0100
 * Upstream subject: lib: Address lwip thread safety
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_netif_init(void)

{
  undefined4 uVar1;
  
  if ((s_nat64_netif[0x187] & 1) == 0) {
    memset(s_nat64_netif,0,0x1a4);
    uVar1 = esp_netif_tcpip_exec(nat64_netif_do_init,0);
    return uVar1;
  }
  return 0;
}

