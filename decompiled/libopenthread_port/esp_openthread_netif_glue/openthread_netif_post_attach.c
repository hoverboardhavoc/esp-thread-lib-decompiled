/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> openthread_netif_post_attach
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int openthread_netif_post_attach(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 *local_30;
  code *pcStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = &s_openthread_netif_glue;
  *(undefined4 *)(param_2 + 4) = param_1;
  uStack_28 = 0;
  uStack_24 = 0;
  pcStack_2c = openthread_netif_transmit;
  iVar1 = esp_netif_set_driver_config(&local_30);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
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
                if (iVar1 == 0) {
                  s_openthread_netif = param_1;
                  iVar1 = esp_event_post(OPENTHREAD_EVENT,0,0,0,0);
                  return iVar1;
                }
                uVar3 = esp_log_timestamp();
                uVar2 = 0xe8;
                puVar4 = &_LC17;
              }
              else {
                uVar3 = esp_log_timestamp();
                uVar2 = 0xe5;
                puVar4 = &_LC16;
              }
            }
            else {
              uVar3 = esp_log_timestamp();
              uVar2 = 0xe2;
              puVar4 = &_LC15;
            }
          }
          else {
            uVar3 = esp_log_timestamp();
            uVar2 = 0xdf;
            puVar4 = &_LC14;
          }
        }
        else {
          uVar3 = esp_log_timestamp();
          uVar2 = 0xdc;
          puVar4 = &_LC13;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        uVar2 = 0xd9;
        puVar4 = &_LC12;
      }
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0xd6;
      puVar4 = &_LC11;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    uVar2 = 0xd3;
    puVar4 = &_LC10;
  }
  esp_log_write(1,"OPENTHREAD",puVar4,uVar3,"OPENTHREAD","register_openthread_event_handlers",uVar2)
  ;
  s_openthread_netif = param_1;
  return iVar1;
}

