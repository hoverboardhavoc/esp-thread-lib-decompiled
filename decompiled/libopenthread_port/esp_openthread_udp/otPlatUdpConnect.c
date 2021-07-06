/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpConnect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUdpConnect(int param_1)

{
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_34 = xTaskGetCurrentTaskHandle();
  uStack_30 = *(undefined4 *)(param_1 + 0x2c);
  uStack_14 = CONCAT22(uStack_14._2_2_,*(undefined2 *)(param_1 + 0x22));
  map_openthread_addr_to_lwip_addr(&local_60,param_1 + 0x12);
  uStack_2c = local_60;
  uStack_28 = uStack_5c;
  uStack_24 = uStack_58;
  uStack_20 = uStack_54;
  uStack_1c = uStack_50;
  uStack_18 = uStack_4c;
  tcpip_callback(udp_connect_task,&uStack_34);
  wait_for_task_notification();
  return uStack_14._2_1_ != '\0';
}

