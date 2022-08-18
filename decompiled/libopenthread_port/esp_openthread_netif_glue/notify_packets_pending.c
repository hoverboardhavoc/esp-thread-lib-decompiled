/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> notify_packets_pending
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 notify_packets_pending(void)

{
  ssize_t sVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  uStack_18 = 1;
  sVar1 = write(DAT_000112a8,&uStack_18,8);
  uVar2 = 0;
  if (sVar1 != 8) {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

