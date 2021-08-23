/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> register_openthread_event_handlers
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int register_openthread_event_handlers(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,0,&esp_netif_action_start,param_1);
  if (iVar1 == 0) {
    iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,1,&esp_netif_action_stop,param_1);
    if (iVar1 == 0) {
      iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,2,&esp_netif_action_connected,param_1);
      if (iVar1 == 0) {
        iVar1 = esp_event_handler_register
                          (OPENTHREAD_EVENT,3,&esp_netif_action_disconnected,param_1);
        if (iVar1 == 0) {
          iVar1 = esp_event_handler_register
                            (OPENTHREAD_EVENT,4,&esp_netif_action_add_ip6_address,param_1);
          if (iVar1 == 0) {
            iVar1 = esp_event_handler_register
                              (OPENTHREAD_EVENT,5,&esp_netif_action_remove_ip6_address,param_1);
            if (iVar1 == 0) {
              iVar1 = esp_event_handler_register
                                (OPENTHREAD_EVENT,6,&esp_netif_action_join_ip6_multicast_group,
                                 param_1);
              if (iVar1 == 0) {
                iVar1 = esp_event_handler_register
                                  (OPENTHREAD_EVENT,7,&esp_netif_action_leave_ip6_multicast_group,
                                   param_1);
                if (iVar1 != 0) {
                  uVar2 = esp_log_timestamp();
                  esp_log_write(1,"OPENTHREAD",&_LC20,uVar2,"OPENTHREAD",
                                "register_openthread_event_handlers",0xe9);
                }
              }
              else {
                uVar2 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC19,uVar2,"OPENTHREAD",
                              "register_openthread_event_handlers",0xe6);
              }
            }
            else {
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC18,uVar2,"OPENTHREAD",
                            "register_openthread_event_handlers",0xe3);
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC17,uVar2,"OPENTHREAD",
                          "register_openthread_event_handlers",0xe0);
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC16,uVar2,"OPENTHREAD",
                        "register_openthread_event_handlers",0xdd);
        }
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC15,uVar2,"OPENTHREAD","register_openthread_event_handlers",
                      0xda);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC14,uVar2,"OPENTHREAD","register_openthread_event_handlers",
                    0xd7);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC13,uVar2,"OPENTHREAD","register_openthread_event_handlers",0xd4
                 );
  }
  return iVar1;
}

