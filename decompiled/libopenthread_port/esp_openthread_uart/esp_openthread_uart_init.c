/*
 * Last changed at upstream commit 33c7be202301956874c23c90dd18e4b791d19c1a
 * https://github.com/espressif/esp-thread-lib/commit/33c7be202301956874c23c90dd18e4b791d19c1a
 * Upstream date: 2021-08-23 19:11:20 +0800
 * Upstream subject: openthread: uses esp log in openthread port
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
  if (*(int *)(param_1 + 0x2c) == 1) {
    s_uart_port = *(undefined4 *)(param_1 + 0x30);
    iVar1 = esp_openthread_uart_init_port(param_1 + 0x30);
    if (iVar1 == 0) {
      esp_vfs_dev_uart_port_set_rx_line_endings(s_uart_port,2);
      if (*(int *)(param_1 + 0x2c) == 1) {
        esp_vfs_dev_uart_port_set_tx_line_endings(s_uart_port,0);
      }
      snprintf(acStack_20,0x10,"/dev/uart/%d");
      s_uart_fd = open(acStack_20,0x4002);
      if (s_uart_fd < 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD","esp_openthread_uart_init",0x68);
        iVar1 = -1;
      }
      else {
        iVar1 = esp_openthread_platform_workflow_register(0x10000,esp_openthread_uart_process,&_LC9)
        ;
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","esp_openthread_uart_init",0x5d);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_uart_init",0x5a);
    iVar1 = -1;
  }
  return iVar1;
}

