/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  iVar2 = esp_netif_receive(DAT_000112a4,param_1,uVar1,0);
  if (iVar2 != 0) {
    uVar1 = esp_log_timestamp();
    uVar3 = esp_err_to_name(iVar2);
    esp_log_write(2,"OPENTHREAD",&_LC18,uVar1,"OPENTHREAD",uVar3);
  }
  otMessageFree(param_1);
  return;
}

