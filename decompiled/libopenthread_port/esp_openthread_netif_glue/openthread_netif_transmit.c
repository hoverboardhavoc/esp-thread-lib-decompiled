/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  }
  else {
    iVar1 = otMessageAppend(param_1,param_2);
    if (iVar1 == 0) {
      iVar2 = xQueueGenericSend(s_packet_queue,aiStack_14,0,0);
      if (iVar2 == 1) {
        iVar2 = notify_packets_pending();
        if (iVar2 != 0) {
          iVar2 = -1;
        }
      }
      else {
        otLogCrit(0xc,"-PLAT----: ","Failed to send to Thread netif: packet queue full");
        iVar2 = 0x101;
      }
    }
    else {
      uVar3 = otThreadErrorToString();
      otLogCrit(0xc,"-PLAT----: ","Failed to copy to OpenThread message: %s",uVar3);
      iVar2 = 0x101;
    }
    if ((iVar1 != 0) && (aiStack_14[0] != 0)) {
      otMessageFree();
    }
  }
  esp_openthread_lock_release();
  return iVar2;
}

