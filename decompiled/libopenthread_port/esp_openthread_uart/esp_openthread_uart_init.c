/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_uart_init(esp_openthread_platform_config_t *config)

{
  int iVar1;
  esp_err_t eVar2;
  undefined4 uVar3;
  char acStack_20 [4];
  char uart_path [16];
  
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 4),(char *)0x0,2,0);
  iVar1 = __getreent();
  setvbuf(*(FILE **)(iVar1 + 8),(char *)0x0,2,0);
  s_uart_port = (config->host_config).host_uart_config.port;
  eVar2 = esp_openthread_uart_init_port(&(config->host_config).host_uart_config);
  if (eVar2 == 0) {
    esp_vfs_dev_uart_port_set_rx_line_endings(s_uart_port,2);
    esp_vfs_dev_uart_port_set_tx_line_endings(s_uart_port,0);
    snprintf(acStack_20,0x10,"/dev/uart/%d");
    s_uart_fd = open(acStack_20,0x4002);
    if (s_uart_fd < 0) {
      eVar2 = -1;
    }
  }
  else {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC4,uVar3,"OPENTHREAD","esp_openthread_uart_init",0x58);
  }
  return eVar2;
}

