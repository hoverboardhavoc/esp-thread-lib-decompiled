/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread.cpp.o -> register_esp_openthread_state_callbacks
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t register_esp_openthread_state_callbacks(void)

{
  int iVar1;
  esp_err_t eVar2;
  undefined4 uVar3;
  
  esp_openthread_get_instance();
  iVar1 = otSetStateChangedCallback(esp_openthread_state_callback,0);
  if (iVar1 == 0) {
    eVar2 = 0;
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD","register_esp_openthread_state_callbacks",
                  0x22);
    eVar2 = -1;
  }
  return eVar2;
}

