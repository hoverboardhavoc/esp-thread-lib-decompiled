/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void esp_openthread_netif_glue_deinit(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_openthread_get_instance();
  otIp6SetAddressCallback(0,0);
  otIp6SetReceiveCallback(uVar1,0,0);
  if (s_packet_queue != (QueueHandle_t)0x0) {
    vQueueDelete();
    s_packet_queue = (QueueHandle_t)0x0;
  }
  if (-1 < s_openthread_netif_glue.event_fd) {
    close(s_openthread_netif_glue.event_fd);
    s_openthread_netif_glue.event_fd = -1;
  }
  iVar2 = esp_event_post(OPENTHREAD_EVENT,1,0,0,0);
  if (iVar2 != 0) {
    otLogCrit(0xc,"-PLAT----: ","Failed to stop OpenThread netif");
  }
  s_openthread_netif = (esp_netif_t *)0x0;
  unregister_openthread_event_handlers();
  return;
}

