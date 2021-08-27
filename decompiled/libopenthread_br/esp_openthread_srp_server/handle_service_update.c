/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
  
  iVar1 = otSrpServerHostIsDeleted(param_2);
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD");
    handle_host_update(param_1,param_2);
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(3,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD");
    handle_host_deleted(param_1,param_2);
  }
  return;
}

