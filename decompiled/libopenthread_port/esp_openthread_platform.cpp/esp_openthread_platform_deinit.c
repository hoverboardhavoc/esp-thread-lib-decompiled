/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_platform_deinit(void)

{
  undefined4 uVar1;
  
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC1,uVar1,"OPENTHREAD","esp_openthread_platform_deinit",0x55);
  return 0x103;
}

