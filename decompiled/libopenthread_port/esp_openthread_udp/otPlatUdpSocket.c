/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  tcpip_callback(udp_new_task,&uStack_1c);
  wait_for_task_notification();
  if (iStack_14 != 0) {
    *(int *)(param_1 + 0x2c) = iStack_14;
  }
  return iStack_14 == 0;
}

