/*
 * Last changed at upstream commit 2fb54104644c7016ba817d08cb7536016bb7c839
 * https://github.com/espressif/esp-thread-lib/commit/2fb54104644c7016ba817d08cb7536016bb7c839
 * Upstream date: 2021-08-20 20:32:33 +0800
 * Upstream subject: update libopenthread_port.a
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
  int aiStack_14 [2];
  
  esp_openthread_lock_acquire(0xffffffff);
  esp_openthread_get_instance();
  aiStack_14[0] = otIp6NewMessage(0);
  if (aiStack_14[0] == 0) {
    otLogCrit(0xc,"-PLAT----: ","Failed to allocate OpenThread message");
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
    otLogCrit(0xc,"-PLAT----: ","Failed to send to Thread netif: packet queue full");
    iVar2 = 0x101;
  }
  else {
    uVar3 = otThreadErrorToString();
    otLogCrit(0xc,"-PLAT----: ","Failed to copy to OpenThread message: %s",uVar3);
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

