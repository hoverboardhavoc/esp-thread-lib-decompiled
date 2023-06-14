/*
 * Last changed at upstream commit 8b9de73a2e7b480096155298de34de510173b675
 * https://github.com/espressif/esp-thread-lib/commit/8b9de73a2e7b480096155298de34de510173b675
 * Upstream date: 2023-06-14 12:30:19 +0800
 * Upstream subject: BR: fix dead lock issue for ot and lwip
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nat64_netif_init(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((s_nat64_netif[0x187] & 1) == 0) {
    memset(s_nat64_netif,0,0x1a4);
    esp_openthread_task_switching_lock_release();
    uVar1 = esp_netif_tcpip_exec(nat64_netif_do_init,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
  }
  return uVar1;
}

