/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int openthread_netif_transmit(undefined4 param_1,undefined2 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int aiStack_14 [2];
  
  esp_openthread_task_switching_lock_acquire();
  esp_openthread_get_instance();
  aiStack_14[0] = otIp6NewMessage(0);
  if (aiStack_14[0] == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC16,uVar1,"OPENTHREAD");
    iVar2 = 0x101;
  }
  else {
    iVar2 = otMessageAppend(param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = xQueueGenericSend(s_packet_queue,aiStack_14,0,0);
      if (iVar2 == 1) {
        iVar2 = notify_packets_pending();
        iVar2 = -(uint)(iVar2 != 0);
        goto _L0;
      }
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC18,uVar1,"OPENTHREAD");
    }
    else {
      uVar1 = esp_log_timestamp();
      uVar3 = otThreadErrorToString(iVar2);
      esp_log_write(1,"OPENTHREAD",&_LC17,uVar1,"OPENTHREAD",uVar3);
    }
    iVar2 = 0x101;
    if (aiStack_14[0] != 0) {
      otMessageFree();
      iVar2 = 0x101;
    }
  }
_L0:
  esp_openthread_task_switching_lock_release();
  return iVar2;
}

