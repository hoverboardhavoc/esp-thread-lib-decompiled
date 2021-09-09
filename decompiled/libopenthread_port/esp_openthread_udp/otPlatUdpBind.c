/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  esp_log_write(3,"OPENTHREAD",&_LC5,uVar1,"OPENTHREAD",*(undefined2 *)((int)param_1 + 0x10));
  uStack_18 = 0x2e;
  memcpy(auStack_2c,param_1,0x10);
  tcpip_callback(udp_bind_task,&uStack_34);
  wait_for_task_notification();
  return cStack_12 != '\0';
}

