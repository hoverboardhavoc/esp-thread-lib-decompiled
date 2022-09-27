/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
  
  if ((DAT_00011304 < 0x40) &&
     ((1 << (DAT_00011304 & 0x1f) & *(uint *)(param_1 + ((int)DAT_00011304 >> 5) * 4)) != 0)) {
    local_1c = 0;
    sVar1 = read(DAT_00011304,auStack_18,8);
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

