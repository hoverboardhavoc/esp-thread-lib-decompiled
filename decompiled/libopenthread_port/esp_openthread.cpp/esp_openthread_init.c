/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  
  iVar1 = esp_openthread_platform_init();
  if (iVar1 == 0) {
    iVar1 = otInstanceInitSingle();
    if (iVar1 == 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_init",0x2b);
      iVar1 = -1;
    }
    else {
      iVar1 = register_esp_openthread_state_callbacks();
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_init",0x29);
  }
  return iVar1;
}

