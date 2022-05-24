/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  
  esp_openthread_lock_acquire(0xffffffff);
  esp_openthread_get_instance();
  aiStack_14[0] = otIp6NewMessage(0);
  if (aiStack_14[0] == 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC20,uVar1,"OPENTHREAD");
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
      esp_log_write(1,"OPENTHREAD",&_LC22,uVar1,"OPENTHREAD");
    }
    else {
      uVar1 = esp_log_timestamp();
      uVar3 = otThreadErrorToString(iVar2);
      esp_log_write(1,"OPENTHREAD",&_LC21,uVar1,"OPENTHREAD",uVar3);
    }
    iVar2 = 0x101;
    if (aiStack_14[0] != 0) {
      otMessageFree();
      iVar2 = 0x101;
    }
  }
_L0:
  esp_openthread_lock_release();
  return iVar2;
}

