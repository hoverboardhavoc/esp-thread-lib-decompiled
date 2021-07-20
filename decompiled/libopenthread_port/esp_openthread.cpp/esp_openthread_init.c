/*
 * Last changed at upstream commit 4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * https://github.com/espressif/esp-thread-lib/commit/4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * Upstream date: 2021-07-20 11:34:17 +0800
 * Upstream subject: openthread: remove build dependency on border router in port library
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
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_init",0x2c);
      iVar1 = -1;
    }
    else {
      iVar1 = register_esp_openthread_state_callbacks();
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_init",0x2a);
  }
  return iVar1;
}

