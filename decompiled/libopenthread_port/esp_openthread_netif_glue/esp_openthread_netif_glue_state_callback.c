/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_netif_glue_state_callback(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  esp_openthread_get_instance();
  if ((s_packet_queue != 0) && ((param_1 & 0x1000000) != 0)) {
    iVar1 = otLinkIsEnabled();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,3,0,0,0);
      if (iVar1 == 0) {
        return;
      }
      uVar2 = esp_log_timestamp();
      puVar3 = &_LC8;
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
      iVar1 = esp_event_post(OPENTHREAD_EVENT,2,0,0,0);
      if (iVar1 == 0) {
        return;
      }
      uVar2 = esp_log_timestamp();
      puVar3 = &_LC6;
    }
    esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD");
    return;
  }
  return;
}

