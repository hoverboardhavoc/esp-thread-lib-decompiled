/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
        *piVar2 = param_1;
        piVar2[1] = 0;
        piVar2[2] = (int)piVar1;
        s_netif_listener_lists = piVar2;
      }
      return;
    }
    if (param_1 == *piVar2) break;
    piVar2 = (int *)piVar2[2];
  }
  return;
}

