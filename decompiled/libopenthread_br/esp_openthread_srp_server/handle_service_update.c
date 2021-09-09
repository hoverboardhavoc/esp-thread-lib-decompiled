/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_service_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_service_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_54 [68];
  
  iVar1 = otSrpServerHostIsDeleted(param_2);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD");
    handle_host_update(param_1,param_2);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_3(auStack_54);
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD",auStack_54);
    iVar1 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar1 != 0);
  }
  return;
}

