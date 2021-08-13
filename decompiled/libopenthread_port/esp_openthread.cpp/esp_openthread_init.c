/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = esp_openthread_platform_init();
  if (iVar1 == 0) {
    iVar2 = otInstanceInitSingle();
    if (iVar2 == 0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD","esp_openthread_init",0x1e);
      iVar1 = -1;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD","esp_openthread_init",0x1c);
  }
  return iVar1;
}

