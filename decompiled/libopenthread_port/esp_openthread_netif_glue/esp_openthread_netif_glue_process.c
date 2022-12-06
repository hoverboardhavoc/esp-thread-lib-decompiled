/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  int local_1c;
  undefined1 auStack_18 [8];
  
  if ((DAT_00011384 < 0x40) &&
     ((1 << (DAT_00011384 & 0x1f) & *(uint *)(param_1 + ((int)DAT_00011384 >> 5) * 4)) != 0)) {
    local_1c = 0;
    sVar1 = read(DAT_00011384,auStack_18,8);
    if (sVar1 == 8) {
      do {
        do {
          iVar2 = xQueueReceive(s_packet_queue,&local_1c,0);
          if (iVar2 != 1) goto _L0;
        } while (local_1c == 0);
        esp_openthread_get_instance();
        iVar2 = otIp6Send(local_1c);
      } while (iVar2 == 0);
      if (iVar2 != 2) {
        uVar3 = esp_log_timestamp();
        uVar4 = otThreadErrorToString(iVar2);
        esp_log_write(2,"OPENTHREAD",&_LC19,uVar3,"OPENTHREAD",uVar4);
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

