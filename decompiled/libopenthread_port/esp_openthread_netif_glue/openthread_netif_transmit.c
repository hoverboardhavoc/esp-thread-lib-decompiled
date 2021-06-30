/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t openthread_netif_transmit(void *handle,void *buffer,size_t len)

{
  esp_err_t eVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iStack_14;
  otMessage *message;
  
  esp_openthread_lock_acquire(0xffffffff);
  esp_openthread_get_instance();
  iStack_14 = otIp6NewMessage(0);
  if (iStack_14 == 0) {
    otLogCrit(0xc,"-PLAT----: ","Failed to allocate OpenThread message");
    eVar1 = 0x101;
  }
  else {
    iVar2 = otMessageAppend(buffer,len & 0xffff);
    if (iVar2 == 0) {
      iVar3 = xQueueGenericSend(s_packet_queue,&iStack_14,0,0);
      if (iVar3 == 1) {
        eVar1 = notify_packets_pending();
        if (eVar1 != 0) {
          eVar1 = -1;
        }
      }
      else {
        otLogCrit(0xc,"-PLAT----: ","Failed to send to Thread netif: packet queue full");
        eVar1 = 0x101;
      }
    }
    else {
      uVar4 = otThreadErrorToString();
      otLogCrit(0xc,"-PLAT----: ","Failed to copy to OpenThread message: %s",uVar4);
      eVar1 = 0x101;
    }
    if ((iVar2 != 0) && (iStack_14 != 0)) {
      otMessageFree();
    }
  }
  esp_openthread_lock_release();
  return eVar1;
}

