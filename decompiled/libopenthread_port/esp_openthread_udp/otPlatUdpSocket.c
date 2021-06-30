/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpSocket
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatUdpSocket(otUdpSocket *udp_socket)

{
  undefined4 uStack_1c;
  udp_new_task_t task;
  
  uStack_1c = 0;
  task.source_task = (TaskHandle_t)0x0;
  task.socket = (otUdpSocket *)0x0;
  uStack_1c = xTaskGetCurrentTaskHandle();
  task.source_task = udp_socket;
  tcpip_callback(udp_new_task,&uStack_1c);
  wait_for_task_notification();
  if (task.socket != (otUdpSocket *)0x0) {
    udp_socket->mHandle = task.socket;
  }
  return (uint)(task.socket == (otUdpSocket *)0x0);
}

