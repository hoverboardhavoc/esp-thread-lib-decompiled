/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  undefined *puVar3;
  undefined4 uVar4;
  
  iVar1 = uart_param_config(*param_1,param_1 + 1);
  if (iVar1 == 0) {
    iVar1 = uart_set_pin(*param_1,param_1[9],param_1[8],0xffffffff,0xffffffff);
    if (iVar1 == 0) {
      iVar1 = uart_driver_install(*param_1,0x100,0,0,0,0);
      if (iVar1 == 0) {
        esp_vfs_dev_uart_use_driver(*param_1);
        return 0;
      }
      uVar2 = esp_log_timestamp();
      uVar4 = 0x49;
      puVar3 = &_LC4;
    }
    else {
      uVar2 = esp_log_timestamp();
      uVar4 = 0x46;
      puVar3 = &_LC3;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x44;
    puVar3 = &_LC2;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD","esp_openthread_uart_init_port",uVar4);
  return iVar1;
}

