/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> handle_service_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_service_update(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = otSrpServerHostIsDeleted(param_2);
  if (iVar1 == 0) {
    otLogInfo(0xc,"-PLAT----: ","Host update");
    handle_host_update(param_1,param_2);
  }
  else {
    otLogInfo(0xc,"-PLAT----: ","Host delete");
    handle_host_deleted(param_1,param_2);
  }
  return;
}

