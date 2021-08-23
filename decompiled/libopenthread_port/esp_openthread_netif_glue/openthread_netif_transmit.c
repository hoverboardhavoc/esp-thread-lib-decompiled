/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int openthread_netif_transmit(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int aiStack_14 [2];
  
  esp_openthread_lock_acquire(0xffffffff);
  esp_openthread_get_instance();
  aiStack_14[0] = otIp6NewMessage(0);
  if (aiStack_14[0] == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC10,uVar3,"OPENTHREAD");
    iVar2 = 0x101;
    goto _L0;
  }
  iVar1 = otMessageAppend(param_1,param_2);
  if (iVar1 == 0) {
    iVar2 = xQueueGenericSend(s_packet_queue,aiStack_14,0,0);
    if (iVar2 == 1) {
      iVar2 = notify_packets_pending();
      if (iVar2 != 0) {
        iVar2 = -1;
      }
      goto _L0;
    }
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC12,uVar3,"OPENTHREAD");
    iVar2 = 0x101;
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar4 = otThreadErrorToString(iVar1);
    esp_log_write(1,"OPENTHREAD",&_LC11,uVar3,"OPENTHREAD",uVar4);
    iVar2 = 0x101;
_L0:
    if (iVar1 == 0) goto _L0;
  }
  if (aiStack_14[0] != 0) {
    otMessageFree();
  }
_L0:
  esp_openthread_lock_release();
  return iVar2;
}

