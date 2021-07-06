/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
        puVar4 = (undefined4 *)__errno();
        otLogWarn(0xc,"-PLAT----: ","read uart failed: %d",*puVar4);
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

