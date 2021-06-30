/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_uart.o -> otPlatUartSend
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatUartSend(uint8_t *buf,uint16_t buf_length)

{
  size_t sVar1;
  undefined2 in_register_0000202e;
  size_t __n;
  
  __n = CONCAT22(in_register_0000202e,buf_length);
  sVar1 = write(s_uart_fd,buf,__n);
  if (__n == sVar1) {
    otPlatUartSendDone();
  }
  return (uint)(__n != sVar1);
}

