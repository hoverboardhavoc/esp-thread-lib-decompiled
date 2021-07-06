/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_platform_update(undefined4 param_1)

{
  esp_openthread_alarm_update();
  if (DAT_000103b0 == 1) {
    esp_openthread_uart_update(param_1);
  }
  esp_openthread_radio_update(param_1);
  esp_openthread_netif_glue_update(param_1);
  esp_openthread_task_queue_update(param_1);
  return;
}

