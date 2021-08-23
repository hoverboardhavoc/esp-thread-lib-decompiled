/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
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
  undefined4 uVar3;
  
  uVar1 = otMessageGetLength();
  iVar2 = esp_netif_receive(_DAT_00010c94,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    uVar3 = esp_err_to_name(iVar2);
    esp_log_write(2,"OPENTHREAD",&_LC24,uVar1,"OPENTHREAD",uVar3);
  }
  otMessageFree(param_1);
  return;
}

