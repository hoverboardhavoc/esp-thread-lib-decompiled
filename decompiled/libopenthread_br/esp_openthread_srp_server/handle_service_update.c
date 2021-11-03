/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
    esp_log_write(3,"OPENTHREAD",&_LC11,uVar2,"OPENTHREAD");
    handle_host_update(param_1,param_2);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC9,uVar2,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_3(auStack_54);
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC10,uVar2,"OPENTHREAD",auStack_54);
    iVar1 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar1 != 0);
  }
  return;
}

