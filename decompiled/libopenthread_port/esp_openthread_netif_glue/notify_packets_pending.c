/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
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
  
  uStack_18 = 1;
  uStack_14 = 0;
  sVar1 = write(DAT_00010c98,&uStack_18,8);
  if (sVar1 == 8) {
    uVar2 = 0;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(2,"OPENTHREAD",&_LC9,uVar2,"OPENTHREAD");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

