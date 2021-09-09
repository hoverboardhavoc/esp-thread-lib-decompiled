/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpSocket
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUdpSocket(int param_1)

{
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  
  uStack_1c = 0;
  iStack_18 = 0;
  iStack_14 = 0;
  uStack_1c = xTaskGetCurrentTaskHandle();
  iStack_18 = param_1;
  tcpip_callback(0x10000,&uStack_1c);
  wait_for_task_notification();
  if (iStack_14 != 0) {
    *(int *)(param_1 + 0x2c) = iStack_14;
  }
  return iStack_14 == 0;
}

