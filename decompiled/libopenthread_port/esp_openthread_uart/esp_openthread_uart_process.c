/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_uart_process(void)

{
  uint uVar1;
  esp_err_t eVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  uVar1 = read(s_uart_fd,s_uart_buffer,0x100);
  if ((int)uVar1 < 1) {
    if ((int)uVar1 < 0) {
      piVar3 = (int *)__errno();
      if (*piVar3 == 0xb) {
        eVar2 = 0;
      }
      else {
        puVar4 = (undefined4 *)__errno();
        otLogWarn(0xc,"-PLAT----: ","read uart failed: %d",*puVar4);
        eVar2 = -1;
      }
    }
    else {
      eVar2 = 0;
    }
  }
  else {
    otPlatUartReceived(s_uart_buffer,uVar1 & 0xffff);
    eVar2 = 0;
  }
  return eVar2;
}

