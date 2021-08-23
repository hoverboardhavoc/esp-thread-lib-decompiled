/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
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
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = esp_openthread_get_instance();
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (s_packet_queue == 0) {
    puVar1 = (undefined4 *)0x0;
    if (DAT_00010c98 < 0) {
      iVar3 = otSetStateChangedCallback(esp_openthread_netif_glue_state_callback,0);
      if (iVar3 == 0) {
        s_packet_queue = xQueueGenericCreate(*(undefined1 *)(param_1 + 0x5c),4,0);
        if (s_packet_queue == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC29,uVar4,"OPENTHREAD");
        }
        else {
          otIp6SetAddressCallback(iVar2,process_thread_address,iVar2);
          otIp6SetReceiveCallback(iVar2,process_thread_receive,iVar2);
          otIp6SetReceiveFilterEnabled(iVar2,1);
          otIcmp6SetEchoMode(iVar2,0);
          DAT_00010c98 = eventfd(0,0);
          if (DAT_00010c98 < 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC30,uVar4,"OPENTHREAD");
          }
          else {
            s_openthread_netif_glue = openthread_netif_post_attach;
            iVar2 = esp_openthread_platform_workflow_register
                              (0x10000,esp_openthread_netif_glue_process,"netif_glue");
            if (iVar2 == 0) {
              puVar1 = &s_openthread_netif_glue;
            }
          }
        }
      }
      else {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC28,uVar4,"OPENTHREAD","esp_openthread_netif_glue_init",
                      0x11b);
      }
    }
  }
  else {
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

