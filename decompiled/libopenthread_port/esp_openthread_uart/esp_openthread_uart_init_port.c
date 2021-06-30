/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_uart_init_port(esp_openthread_uart_config_t *config)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = uart_param_config(config->port,&config->uart_config);
  if (iVar1 == 0) {
    iVar1 = uart_set_pin(config->port,config->tx_pin,config->rx_pin,0xffffffff,0xffffffff);
    if (iVar1 == 0) {
      iVar1 = uart_driver_install(config->port,0x100,0,0,0,0);
      if (iVar1 == 0) {
        esp_vfs_dev_uart_use_driver(config->port);
      }
      else {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_uart_init_port",0x48);
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_uart_init_port",0x46);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD","esp_openthread_uart_init_port",0x43);
  }
  return iVar1;
}

