/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_platform_deinit(void)

{
  undefined4 uVar1;
  
  if (s_openthread_platform_initialized == '\0') {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC4,uVar1,"OPENTHREAD","esp_openthread_platform_deinit",0x8c);
    uVar1 = 0x103;
  }
  else {
    esp_openthread_task_queue_deinit();
    esp_openthread_radio_deinit();
    if (s_platform_config._44_4_ == 1) {
      esp_openthread_uart_deinit();
    }
    esp_openthread_lock_deinit();
    esp_openthread_alarm_deinit();
    uVar1 = 0;
  }
  return uVar1;
}

