/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpBindToNetif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatUdpBindToNetif(otUdpSocket *udp_socket,otNetifIdentifier netif_identifier)

{
  undefined4 uStack_1c;
  udp_bind_netif_task_t task;
  
  uStack_1c = xTaskGetCurrentTaskHandle();
  task.source_task = udp_socket->mHandle;
  task.pcb._0_1_ = get_netif_index(netif_identifier);
  tcpip_callback(udp_bind_netif_task,&uStack_1c);
  wait_for_task_notification();
  return OT_ERROR_NONE;
}

