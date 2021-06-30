/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_platform_update(esp_openthread_mainloop_context_t *mainloop)

{
  esp_openthread_alarm_update();
  if (s_platform_config.host_config.host_connection_mode == HOST_CONNECTION_MODE_UART) {
    esp_openthread_uart_update(mainloop);
  }
  esp_openthread_radio_update(mainloop);
  esp_openthread_netif_glue_update(mainloop);
  esp_openthread_task_queue_update(mainloop);
  return;
}

