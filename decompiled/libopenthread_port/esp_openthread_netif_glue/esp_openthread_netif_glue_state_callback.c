/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_netif_glue_state_callback(otChangedFlags changed_flags)

{
  int iVar1;
  
  esp_openthread_get_instance();
  if ((s_packet_queue != (QueueHandle_t)0x0) && ((int)(changed_flags << 7) < 0)) {
    iVar1 = otLinkIsEnabled();
    if (iVar1 == 0) {
      otLogInfo(0xc,"-PLAT----: ","netif down");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,3,0,0,0);
      if (iVar1 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread if down event");
      }
    }
    else {
      otLogInfo(0xc,"-PLAT----: ","netif up");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,2,0,0,0);
      if (iVar1 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread if up event");
      }
    }
  }
  return;
}

