/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * esp_openthread_netif_glue_init(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = esp_openthread_get_instance();
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (s_packet_queue == 0) {
    puVar1 = (undefined4 *)0x0;
    if (DAT_00010b4c < 0) {
      s_packet_queue = xQueueGenericCreate(*(undefined1 *)(param_1 + 0x5c),4,0);
      if (s_packet_queue == 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to allocate Thread netif packet queue");
      }
      else {
        otIp6SetAddressCallback(iVar2,0x10000,iVar2);
        otIp6SetReceiveCallback(iVar2,process_thread_receive,iVar2);
        otIp6SetReceiveFilterEnabled(iVar2,1);
        otIcmp6SetEchoMode(iVar2,0);
        DAT_00010b4c = eventfd(0,0);
        if (DAT_00010b4c < 0) {
          otLogCrit(0xc,"-PLAT----: ","Failed to create event fd for Thread netif");
        }
        else {
          s_openthread_netif_glue = openthread_netif_post_attach;
          puVar1 = &s_openthread_netif_glue;
        }
      }
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

