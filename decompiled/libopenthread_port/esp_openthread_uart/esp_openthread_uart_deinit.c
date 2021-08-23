/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
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
  esp_openthread_platform_workflow_unregister(&_LC9);
  return;
}

