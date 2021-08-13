/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_uart_deinit(void)

{
  if (s_uart_fd != -1) {
    close(s_uart_fd);
    s_uart_fd = -1;
  }
  uart_driver_delete(s_uart_port);
  esp_openthread_platform_workflow_unregister(&_LC10);
  return;
}

