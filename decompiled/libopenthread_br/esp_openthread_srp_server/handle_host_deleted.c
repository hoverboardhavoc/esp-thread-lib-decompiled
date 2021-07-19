/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_host_deleted
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_host_deleted(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_54 [72];
  
  otSrpServerHostGetFullName(param_2);
  split_hostname(auStack_54,0x40);
  otLogInfo(0xc,"-PLAT----: ","delete host %s",auStack_54);
  iVar1 = mdns_delegate_hostname_remove(auStack_54);
  esp_openthread_get_instance();
  otSrpServerHandleServiceUpdateResult(param_1,iVar1 != 0);
  return;
}

