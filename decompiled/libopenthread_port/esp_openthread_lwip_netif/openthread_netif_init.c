/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
 * Source: libopenthread_port -> esp_openthread_lwip_netif.o -> openthread_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 openthread_netif_init(int param_1)

{
  memset((void *)(param_1 + 0x180),0,6);
  *(undefined2 *)(param_1 + 0x17c) = 0x500;
  *(undefined2 *)(param_1 + 0x186) = 0x208;
  *(undefined2 *)(param_1 + 0x188) = 0x746f;
  *(code **)(param_1 + 0x160) = openthread_output_ip6;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(code **)(param_1 + 0x194) = openthread_netif_multicast_handler;
  netif_set_link_up(param_1);
  return 0;
}

