/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpBind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatUdpBind(otUdpSocket *udp_socket)

{
  undefined4 uVar1;
  undefined4 uStack_34;
  udp_bind_connect_task_t task;
  
  uStack_34 = 0;
  task.source_task = (TaskHandle_t)0x0;
  task.pcb = (udp_pcb *)0x0;
  task.addr.u_addr.ip6.addr[0] = 0;
  task.addr.u_addr.ip6.addr[1] = 0;
  task.addr.u_addr.ip6.addr[2] = 0;
  task.addr.u_addr.ip6.addr[3] = 0;
  task.addr.u_addr._16_4_ = 0;
  task.addr.type = '\0';
  task.addr._21_3_ = 0;
  uStack_34 = xTaskGetCurrentTaskHandle();
  task.source_task = udp_socket->mHandle;
  task.addr._20_2_ = (udp_socket->mSockName).mPort;
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC6,uVar1,"OPENTHREAD",(udp_socket->mSockName).mPort);
  task.addr.u_addr.ip6.zone = 0x2e;
  memcpy(&task.pcb,udp_socket,0x10);
  tcpip_callback(udp_bind_task,&uStack_34);
  wait_for_task_notification();
  return (uint)(task.addr._22_1_ != '\0');
}

