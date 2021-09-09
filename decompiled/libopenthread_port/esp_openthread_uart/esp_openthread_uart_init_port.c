/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
      uVar4 = 0x4a;
      puVar3 = &_LC4;
    }
    else {
      uVar2 = esp_log_timestamp();
      uVar4 = 0x48;
      puVar3 = &_LC3;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x45;
    puVar3 = &_LC2;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar2,"OPENTHREAD","esp_openthread_uart_init_port",uVar4);
  return iVar1;
}

