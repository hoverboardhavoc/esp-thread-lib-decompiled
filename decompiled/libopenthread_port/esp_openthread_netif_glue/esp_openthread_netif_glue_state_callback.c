/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_state_callback(int param_1)

{
  int iVar1;
  
  esp_openthread_get_instance();
  if ((s_packet_queue != 0) && (param_1 << 7 < 0)) {
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

