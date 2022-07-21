/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
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
  iVar2 = esp_netif_receive(DAT_0001128c,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    uVar3 = esp_err_to_name(iVar2);
    esp_log_write(2,"OPENTHREAD",&_L0,uVar1,"OPENTHREAD",uVar3);
  }
  otMessageFree(param_1);
  return;
}

