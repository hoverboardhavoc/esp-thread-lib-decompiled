/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpBindToNetif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatUdpBindToNetif(int param_1,undefined4 param_2)

{
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  uStack_1c = xTaskGetCurrentTaskHandle();
  uStack_18 = *(undefined4 *)(param_1 + 0x2c);
  uStack_14 = get_netif_index(param_2);
  tcpip_callback(udp_bind_netif_task,&uStack_1c);
  wait_for_task_notification();
  return 0;
}

