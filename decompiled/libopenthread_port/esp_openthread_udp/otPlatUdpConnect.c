/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpConnect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUdpConnect(int param_1)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [24];
  undefined2 uStack_14;
  char cStack_12;
  
  memset(&uStack_34,0,0x24);
  uStack_34 = xTaskGetCurrentTaskHandle();
  uStack_30 = *(undefined4 *)(param_1 + 0x2c);
  uStack_14 = *(undefined2 *)(param_1 + 0x22);
  map_openthread_addr_to_lwip_addr(auStack_2c,param_1 + 0x12);
  tcpip_callback(udp_connect_task,&uStack_34);
  wait_for_task_notification();
  return cStack_12 != '\0';
}

