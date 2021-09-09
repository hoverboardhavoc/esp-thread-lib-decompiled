/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  undefined *puVar3;
  undefined4 uVar4;
  char acStack_30 [28];
  
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 4),(char *)0x0,2,0);
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 8),(char *)0x0,2,0);
  if (1 < *(int *)(param_1 + 0x2c) - 1U) {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x5a;
    puVar3 = &_LC5;
    goto _L0;
  }
  s_uart_port = *(undefined4 *)(param_1 + 0x30);
  iVar1 = esp_openthread_uart_init_port(param_1 + 0x30);
  if (iVar1 != 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC6,uVar4,"OPENTHREAD","esp_openthread_uart_init",0x5d);
    return iVar1;
  }
  esp_vfs_dev_uart_port_set_rx_line_endings(s_uart_port,2);
  uVar4 = 0;
  if (*(int *)(param_1 + 0x2c) == 1) {
_L32:
    esp_vfs_dev_uart_port_set_tx_line_endings(s_uart_port,uVar4);
  }
  else if (*(int *)(param_1 + 0x2c) == 2) {
    uVar4 = 2;
    goto _L32;
  }
  snprintf(acStack_30,0x10,"/dev/uart/%d");
  s_uart_fd = open(acStack_30,0x4002);
  if (-1 < s_uart_fd) {
    iVar1 = esp_openthread_platform_workflow_register(0x10000,esp_openthread_uart_process,&_LC9);
    return iVar1;
  }
  uVar2 = esp_log_timestamp();
  uVar4 = 0x68;
  puVar3 = &_LC8;
_L0:
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD","esp_openthread_uart_init",uVar4);
  return -1;
}

