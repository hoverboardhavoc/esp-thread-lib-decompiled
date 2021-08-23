/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_uart_process(void)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  uVar1 = read(s_uart_fd,s_uart_buffer,0x100);
  if ((int)uVar1 < 1) {
    if ((int)uVar1 < 0) {
      piVar3 = (int *)__errno();
      if (*piVar3 == 0xb) {
        uVar2 = 0;
      }
      else {
        uVar2 = esp_log_timestamp();
        puVar4 = (undefined4 *)__errno();
        esp_log_write(2,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",*puVar4);
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    otPlatUartReceived(s_uart_buffer,uVar1 & 0xffff);
    uVar2 = 0;
  }
  return uVar2;
}

