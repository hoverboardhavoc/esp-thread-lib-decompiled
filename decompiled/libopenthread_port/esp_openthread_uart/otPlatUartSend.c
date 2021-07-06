/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_uart.o -> otPlatUartSend
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatUartSend(void *param_1,size_t param_2)

{
  size_t sVar1;
  
  sVar1 = write(s_uart_fd,param_1,param_2);
  if (param_2 == sVar1) {
    otPlatUartSendDone();
  }
  return param_2 != sVar1;
}

