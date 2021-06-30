/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t process_thread_transmit(otInstance *instance)

{
  int unaff_s0;
  ssize_t sVar1;
  int iVar2;
  esp_err_t eVar3;
  undefined4 uVar4;
  undefined1 auStack_20 [4];
  uint64_t event;
  int local_14;
  otMessage *msg;
  
  local_14 = 0;
  sVar1 = read(s_openthread_netif_glue.event_fd,auStack_20,8);
  if (sVar1 != 8) {
    __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
                  ,0x83,"process_thread_transmit","ret == sizeof(event)");
    goto _L0;
  }
  do {
    do {
      iVar2 = xQueueReceive(s_packet_queue,&local_14,0);
      if (iVar2 != 1) goto _L0;
    } while (local_14 == 0);
    esp_openthread_get_instance();
    unaff_s0 = otIp6Send(local_14);
    if ((unaff_s0 != 0) && (unaff_s0 != 2)) {
_L0:
      uVar4 = otThreadErrorToString();
      otLogWarn(0xc,"-PLAT----: ","ThreadNetif Failed to send OpenThread IP6 message: %s",uVar4);
    }
  } while (unaff_s0 == 0);
_L0:
  iVar2 = uxQueueMessagesWaiting(s_packet_queue);
  if (iVar2 == 0) {
    eVar3 = 0;
  }
  else {
    eVar3 = notify_packets_pending();
  }
  return eVar3;
}

