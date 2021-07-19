/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *__src;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
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
  otLogInfo(0xc,"-PLAT----: ","update host %s",auStack_64);
  iVar2 = mdns_hostname_exists(auStack_64);
  if (iVar2 == 0) {
    __src = (void *)otSrpServerHostGetAddresses(param_2,auStack_ec);
    uStack_94 = 6;
    memcpy(auStack_a8,__src,0x10);
    uStack_98 = 0;
    uStack_90 = 0;
    uVar4 = ip6addr_ntoa(auStack_a8);
    otLogInfo(0xc,"-PLAT----: ","Add new host, addr %s",uVar4);
    iVar2 = mdns_delegate_hostname_add(auStack_64,auStack_a8);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 0;
  }
  iVar1 = 0;
  do {
    iVar1 = otSrpServerHostGetNextService(param_2,iVar1);
    if (iVar1 == 0) break;
    otSrpServerServiceGetFullName(iVar1);
    local_f5 = -1;
    split_service_name(auStack_ec,0x40,auStack_a8,0x40,auStack_f4,5);
    otLogInfo(0xc,"-PLAT----: ","Service %s.%s.%s",auStack_ec,auStack_a8,auStack_f4);
    iVar3 = otSrpServerServiceIsDeleted(iVar1);
    if ((iVar3 == 0) && (iVar3 = mdns_service_exists(auStack_a8,auStack_f4,auStack_64), iVar3 == 0))
    {
      otLogInfo(0xc,"-PLAT----: ","Add new service");
      uVar4 = otSrpServerServiceGetPort(iVar1);
      iVar3 = mdns_service_add_for_host(auStack_ec,auStack_a8,auStack_f4,auStack_64,uVar4,0,0);
      if (iVar3 != 0) {
        iVar2 = 1;
        break;
      }
    }
    else {
      iVar3 = otSrpServerServiceIsDeleted(iVar1);
      if ((iVar3 != 0) &&
         (iVar3 = mdns_service_remove_for_host(auStack_a8,auStack_f4,auStack_64), iVar3 != 0)) {
        iVar2 = 1;
        break;
      }
    }
    iVar3 = alloc_txt_list(iVar1,&local_f5);
    if ((local_f5 == '\0') || (iVar3 != 0)) {
      if ((local_f5 != '\0') &&
         (iVar5 = mdns_service_txt_set_for_host(auStack_a8,auStack_f4,auStack_64,iVar3), iVar5 != 0)
         ) {
        iVar2 = 1;
      }
    }
    else {
      iVar2 = 3;
    }
    free_txt_list(iVar3,local_f5);
  } while (iVar2 == 0);
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar2);
  return;
}

