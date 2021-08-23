/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_deinit(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_openthread_get_instance();
  otIp6SetAddressCallback(0,0);
  otIp6SetReceiveCallback(uVar1,0,0);
  if (s_packet_queue != 0) {
    vQueueDelete();
    s_packet_queue = 0;
  }
  if (-1 < DAT_00010c98) {
    close(DAT_00010c98);
    DAT_00010c98 = -1;
  }
  iVar2 = esp_event_post(OPENTHREAD_EVENT,1,0,0,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC32,uVar1,"OPENTHREAD");
  }
  s_openthread_netif = 0;
  unregister_openthread_event_handlers();
  esp_openthread_platform_workflow_unregister("netif_glue");
  return;
}

