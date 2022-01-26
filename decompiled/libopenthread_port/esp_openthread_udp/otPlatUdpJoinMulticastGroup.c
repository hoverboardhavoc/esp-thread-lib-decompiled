/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpJoinMulticastGroup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatUdpJoinMulticastGroup(undefined4 param_1,void *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined1 *)malloc(0x18);
  uVar3 = 3;
  if (puVar2 != (undefined1 *)0x0) {
    memcpy(puVar2 + 4,param_2,0x10);
    *puVar2 = 1;
    uVar1 = get_netif_index(param_1);
    puVar2[1] = uVar1;
    tcpip_callback(udp_multicast_join_leave_task,puVar2);
    uVar3 = 0;
  }
  return uVar3;
}

