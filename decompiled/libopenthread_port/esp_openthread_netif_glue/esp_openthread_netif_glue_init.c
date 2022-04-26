/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * esp_openthread_netif_glue_init(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  iVar1 = esp_openthread_get_instance();
  if (((iVar1 != 0) && (s_packet_queue == 0)) && (DAT_00010ae0 < 0)) {
    iVar2 = otSetStateChangedCallback(esp_openthread_netif_glue_state_callback,0);
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC24,uVar3,"OPENTHREAD","esp_openthread_netif_glue_init",0x11b)
      ;
      return (undefined4 *)0x0;
    }
    s_packet_queue = xQueueGenericCreate(*(undefined1 *)(param_1 + 0x5c),4,0);
    if (s_packet_queue == 0) {
      uVar3 = esp_log_timestamp();
      puVar4 = &_LC25;
    }
    else {
      otIp6SetAddressCallback(iVar1,process_thread_address,iVar1);
      otIp6SetReceiveCallback(iVar1,process_thread_receive,iVar1);
      otIp6SetReceiveFilterEnabled(iVar1,1);
      otIcmp6SetEchoMode(iVar1,0);
      DAT_00010ae0 = eventfd(0,0);
      if (-1 < DAT_00010ae0) {
        s_openthread_netif_glue = openthread_netif_post_attach;
        iVar1 = esp_openthread_platform_workflow_register
                          (0x10000,esp_openthread_netif_glue_process,"netif_glue");
        if (iVar1 != 0) {
          return (undefined4 *)0x0;
        }
        return &s_openthread_netif_glue;
      }
      uVar3 = esp_log_timestamp();
      puVar4 = &_LC26;
    }
    esp_log_write(1,"OPENTHREAD",puVar4,uVar3,"OPENTHREAD");
  }
  return (undefined4 *)0x0;
}

