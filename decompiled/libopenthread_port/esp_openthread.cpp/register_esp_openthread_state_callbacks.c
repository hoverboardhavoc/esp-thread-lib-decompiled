/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread.cpp.o -> register_esp_openthread_state_callbacks
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* register_esp_openthread_state_callbacks() */

undefined4 register_esp_openthread_state_callbacks(void)

{
  int iVar1;
  undefined4 uVar2;
  
  esp_openthread_get_instance();
  iVar1 = otSetStateChangedCallback(esp_openthread_state_callback,0);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD","register_esp_openthread_state_callbacks",
                  0x22);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

