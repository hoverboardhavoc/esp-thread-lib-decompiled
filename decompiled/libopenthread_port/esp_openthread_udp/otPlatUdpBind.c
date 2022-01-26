/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpBind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUdpBind(void *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [20];
  undefined1 uStack_18;
  undefined2 uStack_14;
  char cStack_12;
  
  memset(&uStack_34,0,0x24);
  uStack_34 = xTaskGetCurrentTaskHandle();
  uStack_30 = *(undefined4 *)((int)param_1 + 0x2c);
  uStack_14 = *(undefined2 *)((int)param_1 + 0x10);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC7,uVar1,"OPENTHREAD",*(undefined2 *)((int)param_1 + 0x10));
  uStack_18 = 0x2e;
  memcpy(auStack_2c,param_1,0x10);
  tcpip_callback(udp_bind_task,&uStack_34);
  wait_for_task_notification();
  return cStack_12 != '\0';
}

