/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 process_thread_transmit(void)

{
  int unaff_s0;
  ssize_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_20 [12];
  int local_14 [3];
  
  local_14[0] = 0;
  sVar1 = read(DAT_00010b80,auStack_20,8);
  if (sVar1 != 8) {
    __assert_func("//home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_netif_glue.c"
                  ,0x7e,"process_thread_transmit","ret == sizeof(event)");
    goto _L0;
  }
  do {
    do {
      iVar2 = xQueueReceive(s_packet_queue,local_14,0);
      if (iVar2 != 1) goto _L0;
    } while (local_14[0] == 0);
    esp_openthread_get_instance();
    unaff_s0 = otIp6Send(local_14[0]);
    if ((unaff_s0 != 0) && (unaff_s0 != 2)) {
_L0:
      uVar3 = otThreadErrorToString();
      otLogWarn(0xc,"-PLAT----: ","ThreadNetif Failed to send OpenThread IP6 message: %s",uVar3);
    }
  } while (unaff_s0 == 0);
_L0:
  iVar2 = uxQueueMessagesWaiting(s_packet_queue);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = notify_packets_pending();
  }
  return uVar3;
}

