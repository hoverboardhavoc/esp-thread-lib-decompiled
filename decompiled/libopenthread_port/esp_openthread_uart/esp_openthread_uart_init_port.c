/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_uart.o -> esp_openthread_uart_init_port
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_uart_init_port(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = uart_param_config(*param_1,param_1 + 1);
  if (iVar1 == 0) {
    iVar1 = uart_set_pin(*param_1,param_1[9],param_1[8],0xffffffff,0xffffffff);
    if (iVar1 == 0) {
      iVar1 = uart_driver_install(*param_1,0x100,0,0,0,0);
      if (iVar1 == 0) {
        esp_vfs_dev_uart_use_driver(*param_1);
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

