/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *__src;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char local_f5;
  undefined1 auStack_f4 [8];
  undefined1 auStack_ec [68];
  undefined1 auStack_a8 [16];
  undefined1 uStack_98;
  undefined1 uStack_94;
  undefined4 uStack_90;
  undefined1 auStack_64 [76];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname(auStack_64,0x40);
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD",auStack_64);
  iVar3 = mdns_hostname_exists(auStack_64);
  if (iVar3 == 0) {
    __src = (void *)otSrpServerHostGetAddresses(param_2,auStack_ec);
    uStack_94 = 6;
    memcpy(auStack_a8,__src,0x10);
    uStack_98 = 0;
    uStack_90 = 0;
    uVar2 = esp_log_timestamp();
    uVar4 = ip6addr_ntoa(auStack_a8);
    esp_log_write(3,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD",uVar4);
    iVar3 = mdns_delegate_hostname_add(auStack_64,auStack_a8);
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 0;
  }
  iVar1 = 0;
  do {
    iVar1 = otSrpServerHostGetNextService(param_2,iVar1);
    if (iVar1 == 0) break;
    otSrpServerServiceGetFullName(iVar1);
    local_f5 = -1;
    split_service_name(auStack_ec,0x40,auStack_a8,0x40,auStack_f4,5);
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD",auStack_ec,auStack_a8,auStack_f4);
    iVar5 = otSrpServerServiceIsDeleted(iVar1);
    if ((iVar5 == 0) && (iVar5 = mdns_service_exists(auStack_a8,auStack_f4,auStack_64), iVar5 == 0))
    {
      uVar2 = esp_log_timestamp();
      esp_log_write(3,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
      uVar2 = otSrpServerServiceGetPort(iVar1);
      iVar5 = mdns_service_add_for_host(auStack_ec,auStack_a8,auStack_f4,auStack_64,uVar2,0,0);
      if (iVar5 != 0) {
        iVar3 = 1;
        break;
      }
    }
    else {
      iVar5 = otSrpServerServiceIsDeleted(iVar1);
      if ((iVar5 != 0) &&
         (iVar5 = mdns_service_remove_for_host(auStack_a8,auStack_f4,auStack_64), iVar5 != 0)) {
        iVar3 = 1;
        break;
      }
    }
    iVar5 = alloc_txt_list(iVar1,&local_f5);
    if ((local_f5 == '\0') || (iVar5 != 0)) {
      if ((local_f5 != '\0') &&
         (iVar6 = mdns_service_txt_set_for_host(auStack_a8,auStack_f4,auStack_64,iVar5), iVar6 != 0)
         ) {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 3;
    }
    free_txt_list(iVar5,local_f5);
  } while (iVar3 == 0);
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar3);
  return;
}

