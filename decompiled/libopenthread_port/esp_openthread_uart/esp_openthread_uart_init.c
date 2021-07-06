/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_uart_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_20 [20];
  
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 4),(char *)0x0,2,0);
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 8),(char *)0x0,2,0);
  s_uart_port = *(undefined4 *)(param_1 + 0x30);
  iVar1 = esp_openthread_uart_init_port(param_1 + 0x30);
  if (iVar1 == 0) {
    esp_vfs_dev_uart_port_set_rx_line_endings(s_uart_port,2);
    esp_vfs_dev_uart_port_set_tx_line_endings(s_uart_port,0);
    snprintf(acStack_20,0x10,"/dev/uart/%d");
    s_uart_fd = open(acStack_20,0x4002);
    if (s_uart_fd < 0) {
      iVar1 = -1;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD","esp_openthread_uart_init",0x58);
  }
  return iVar1;
}

