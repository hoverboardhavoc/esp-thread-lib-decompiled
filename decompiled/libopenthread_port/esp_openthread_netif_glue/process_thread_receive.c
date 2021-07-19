/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void process_thread_receive(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = otMessageGetLength();
  iVar2 = esp_netif_receive(_DAT_00010af8,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_err_to_name();
    otLogWarn(0xc,"-PLAT----: ","process_thread_receive failed: %s",uVar1);
  }
  otMessageFree(param_1);
  return;
}

