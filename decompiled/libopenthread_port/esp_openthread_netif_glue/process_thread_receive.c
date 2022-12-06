/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  undefined4 uVar3;
  
  uVar1 = otMessageGetLength();
  iVar2 = esp_netif_receive(DAT_00011380,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    uVar3 = esp_err_to_name(iVar2);
    esp_log_write(2,"OPENTHREAD",&_LC14,uVar1,"OPENTHREAD",uVar3);
  }
  otMessageFree(param_1);
  return;
}

