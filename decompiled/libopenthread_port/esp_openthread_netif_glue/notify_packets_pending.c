/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
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
  sVar1 = write(DAT_00011290,&uStack_18,8);
  uVar2 = 0;
  if (sVar1 != 8) {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

