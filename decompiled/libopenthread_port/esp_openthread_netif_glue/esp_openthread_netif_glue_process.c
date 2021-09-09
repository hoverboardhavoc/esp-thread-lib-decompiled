/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_netif_glue_process(int param_1)

{
  ssize_t sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_2c;
  undefined1 auStack_28 [20];
  
  if ((s_openthread_netif_glue < 0x40) &&
     ((1 << (s_openthread_netif_glue & 0x1f) &
      *(uint *)(param_1 + (s_openthread_netif_glue >> 5) * 4)) != 0)) {
    local_2c = 0;
    sVar1 = read(s_openthread_netif_glue,auStack_28,8);
    if (sVar1 == 8) {
      do {
        do {
          iVar2 = xQueueReceive(s_packet_queue,&local_2c,0);
          if (iVar2 != 1) goto _L0;
        } while (local_2c == 0);
        esp_openthread_get_instance();
        iVar2 = otIp6Send(local_2c);
      } while (iVar2 == 0);
      if (iVar2 != 2) {
        uVar3 = esp_log_timestamp();
        uVar4 = otThreadErrorToString(iVar2);
        esp_log_write(2,"OPENTHREAD",&_LC23,uVar3,"OPENTHREAD",uVar4);
      }
_L0:
      iVar2 = uxQueueMessagesWaiting(s_packet_queue);
      uVar3 = 0;
      if (iVar2 != 0) {
        uVar3 = notify_packets_pending();
      }
      return uVar3;
    }
    __assert_func(0,0,0,0);
  }
  return 0;
}

