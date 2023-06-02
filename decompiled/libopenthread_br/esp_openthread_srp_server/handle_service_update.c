/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
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
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
    otSrpServerHostGetFullName(param_2);
    split_hostname_constprop_0(auStack_54);
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC13,uVar2,"OPENTHREAD",auStack_54);
    iVar1 = mdns_delegate_hostname_remove(auStack_54);
    esp_openthread_get_instance();
    otSrpServerHandleServiceUpdateResult(param_1,iVar1 != 0);
    return;
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC14,uVar2,"OPENTHREAD");
  handle_host_update(param_1,param_2);
  return;
}

