/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> notify_packets_pending
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t notify_packets_pending(void)

{
  ssize_t sVar1;
  esp_err_t eVar2;
  undefined4 uStack_18;
  uint64_t signal;
  
  uStack_18 = 1;
  signal._0_4_ = 0;
  sVar1 = write(s_openthread_netif_glue.event_fd,&uStack_18,8);
  if (sVar1 == 8) {
    eVar2 = 0;
  }
  else {
    otLogWarn(0xc,"-PLAT----: ","Thread netif failed to notify eventfd");
    eVar2 = -1;
  }
  return eVar2;
}

