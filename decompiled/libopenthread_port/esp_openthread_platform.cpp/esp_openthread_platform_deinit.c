/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar1,"OPENTHREAD","esp_openthread_platform_deinit",0x8d);
    uVar1 = 0x103;
  }
  else {
    esp_openthread_task_queue_deinit();
    esp_openthread_radio_deinit();
    if (s_platform_config == 1) {
      esp_openthread_uart_deinit();
    }
    esp_openthread_lock_deinit();
    esp_openthread_alarm_deinit();
    uVar1 = 0;
  }
  return uVar1;
}

