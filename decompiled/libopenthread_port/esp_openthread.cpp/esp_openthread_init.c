/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = esp_openthread_platform_init();
  if (iVar1 == 0) {
    esp_openthread_lock_acquire(0xffffffff);
    iVar3 = otInstanceInitSingle();
    if (iVar3 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_init",0x21);
      iVar1 = -1;
    }
    else {
      esp_openthread_lock_release();
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_init",0x1e);
  }
  return iVar1;
}

