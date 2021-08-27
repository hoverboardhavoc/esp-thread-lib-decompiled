/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
  uStack_30 = *(undefined4 *)((int)param_1 + 0x2c);
  uStack_14 = CONCAT22(uStack_14._2_2_,*(undefined2 *)((int)param_1 + 0x10));
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD",*(undefined2 *)((int)param_1 + 0x10));
  uStack_18 = CONCAT31(uStack_18._1_3_,0x2e);
  memcpy(&uStack_2c,param_1,0x10);
  tcpip_callback(udp_bind_task,&uStack_34);
  wait_for_task_notification();
  return uStack_14._2_1_ != '\0';
}

