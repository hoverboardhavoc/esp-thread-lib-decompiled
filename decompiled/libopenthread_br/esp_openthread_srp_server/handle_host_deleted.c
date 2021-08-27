/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_deleted
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_deleted(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_54 [72];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname(auStack_54,0x40);
  uVar1 = esp_log_timestamp();
  esp_log_write(3,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD",auStack_54);
  iVar2 = mdns_delegate_hostname_remove(auStack_54);
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar2 != 0);
  return;
}

