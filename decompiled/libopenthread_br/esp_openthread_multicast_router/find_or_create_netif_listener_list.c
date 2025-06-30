/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> find_or_create_netif_listener_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void find_or_create_netif_listener_list(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = s_netif_listener_lists;
  piVar2 = s_netif_listener_lists;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)malloc(0xc);
      if (piVar2 != (int *)0x0) {
        piVar2[1] = 0;
        piVar2[2] = (int)piVar1;
        *piVar2 = param_1;
        s_netif_listener_lists = piVar2;
      }
      return;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)piVar2[2];
  }
  return;
}

