/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_uart_process(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar1 = read(s_uart_fd,s_uart_buffer,0x100);
  if ((int)uVar1 < 1) {
    if ((uVar1 != 0) && (piVar2 = (int *)__errno(), *piVar2 != 0xb)) {
      uVar3 = esp_log_timestamp();
      puVar4 = (undefined4 *)__errno();
      esp_log_write(2,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD",*puVar4);
      return 0xffffffff;
    }
  }
  else {
    otPlatUartReceived(s_uart_buffer,uVar1 & 0xffff);
  }
  return 0;
}

