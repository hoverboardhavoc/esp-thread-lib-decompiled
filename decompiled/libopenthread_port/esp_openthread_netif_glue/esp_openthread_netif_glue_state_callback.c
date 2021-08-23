/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_state_callback(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  esp_openthread_get_instance();
  if ((s_packet_queue != 0) && (param_1 << 7 < 0)) {
    iVar1 = otLinkIsEnabled();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,3,0,0,0);
      if (iVar1 != 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD");
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,2,0,0,0);
      if (iVar1 != 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD");
      }
    }
  }
  return;
}

