/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpConnect
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUdpConnect(int param_1)

{
  undefined1 auStack_60 [44];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [24];
  undefined2 uStack_14;
  char cStack_12;
  
  memset(&uStack_34,0,0x24);
  uStack_34 = xTaskGetCurrentTaskHandle();
  uStack_30 = *(undefined4 *)(param_1 + 0x2c);
  uStack_14 = *(undefined2 *)(param_1 + 0x22);
  map_openthread_addr_to_lwip_addr(auStack_60,param_1 + 0x12);
  memcpy(auStack_2c,auStack_60,0x18);
  tcpip_callback(udp_connect_task,&uStack_34);
  wait_for_task_notification();
  return cStack_12 != '\0';
}

