/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> register_openthread_event_handlers
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t register_openthread_event_handlers(esp_netif_t *esp_netif)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,0,&esp_netif_action_start,esp_netif);
  if (iVar1 == 0) {
    iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,1,&esp_netif_action_stop,esp_netif);
    if (iVar1 == 0) {
      iVar1 = esp_event_handler_register(OPENTHREAD_EVENT,2,&esp_netif_action_connected,esp_netif);
      if (iVar1 == 0) {
        iVar1 = esp_event_handler_register
                          (OPENTHREAD_EVENT,3,&esp_netif_action_disconnected,esp_netif);
        if (iVar1 == 0) {
          iVar1 = esp_event_handler_register
                            (OPENTHREAD_EVENT,4,&esp_netif_action_add_ip6_address,esp_netif);
          if (iVar1 == 0) {
            iVar1 = esp_event_handler_register
                              (OPENTHREAD_EVENT,5,&esp_netif_action_remove_ip6_address,esp_netif);
            if (iVar1 == 0) {
              iVar1 = esp_event_handler_register
                                (OPENTHREAD_EVENT,6,&esp_netif_action_join_ip6_multicast_group,
                                 esp_netif);
              if (iVar1 == 0) {
                iVar1 = esp_event_handler_register
                                  (OPENTHREAD_EVENT,7,&esp_netif_action_leave_ip6_multicast_group,
                                   esp_netif);
                if (iVar1 != 0) {
                  uVar2 = esp_log_timestamp();
                  esp_log_write(1,"OPENTHREAD",&_LC17,uVar2,"OPENTHREAD",
                                "register_openthread_event_handlers",0xed);
                }
              }
              else {
                uVar2 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC16,uVar2,"OPENTHREAD",
                              "register_openthread_event_handlers",0xea);
              }
            }
            else {
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC15,uVar2,"OPENTHREAD",
                            "register_openthread_event_handlers",0xe7);
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC14,uVar2,"OPENTHREAD",
                          "register_openthread_event_handlers",0xe4);
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC13,uVar2,"OPENTHREAD",
                        "register_openthread_event_handlers",0xe1);
        }
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC12,uVar2,"OPENTHREAD","register_openthread_event_handlers",
                      0xde);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC11,uVar2,"OPENTHREAD","register_openthread_event_handlers",
                    0xdb);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC10,uVar2,"OPENTHREAD","register_openthread_event_handlers",0xd8
                 );
  }
  return iVar1;
}

