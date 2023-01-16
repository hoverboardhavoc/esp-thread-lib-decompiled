/*
 * Last changed at upstream commit 99779af83df3c13d358e1dab7f19699237b1ffdc
 * https://github.com/espressif/esp-thread-lib/commit/99779af83df3c13d358e1dab7f19699237b1ffdc
 * Upstream date: 2023-01-16 10:21:19 +0100
 * Upstream subject: lib: Address lwip thread-safety/core-locking
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

