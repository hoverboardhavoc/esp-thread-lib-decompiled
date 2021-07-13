/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void esp_openthread_platform_update(undefined4 param_1)

{
  esp_openthread_alarm_update();
  if (_DAT_000103b4 == 1) {
    esp_openthread_uart_update(param_1);
  }
  esp_openthread_radio_update(param_1);
  esp_openthread_netif_glue_update(param_1);
  esp_openthread_task_queue_update(param_1);
  return;
}

