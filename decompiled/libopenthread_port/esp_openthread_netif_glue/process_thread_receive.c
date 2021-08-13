/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void process_thread_receive(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = otMessageGetLength();
  iVar2 = esp_netif_receive(DAT_00010b7c,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_err_to_name();
    otLogWarn(0xc,"-PLAT----: ","process_thread_receive failed: %s",uVar1);
  }
  otMessageFree(param_1);
  return;
}

