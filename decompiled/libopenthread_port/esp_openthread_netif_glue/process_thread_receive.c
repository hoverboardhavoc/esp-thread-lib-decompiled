/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  iVar2 = esp_netif_receive(DAT_0001137c,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    uVar3 = esp_err_to_name(iVar2);
    esp_log_write(2,"OPENTHREAD",&_LC14,uVar1,"OPENTHREAD",uVar3);
  }
  otMessageFree(param_1);
  return;
}

