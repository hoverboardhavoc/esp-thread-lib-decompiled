/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  sVar1 = write(DAT_00010b4c,&uStack_18,8);
  if (sVar1 == 8) {
    uVar2 = 0;
  }
  else {
    otLogWarn(0xc,"-PLAT----: ","Thread netif failed to notify eventfd");
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

