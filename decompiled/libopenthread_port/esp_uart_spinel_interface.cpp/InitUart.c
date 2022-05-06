/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> InitUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::InitUart(esp_openthread_uart_config_t const&) */

int __thiscall
esp::openthread::UartSpinelInterface::InitUart
          (UartSpinelInterface *this,esp_openthread_uart_config_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_20 [16];
  
  memcpy(this + 0x24,param_1,0x28);
  iVar1 = esp_openthread_uart_init_port(param_1);
  if (iVar1 == 0) {
    esp_vfs_dev_uart_port_set_tx_line_endings(*(undefined4 *)(this + 0x24),2);
    esp_vfs_dev_uart_port_set_rx_line_endings(*(undefined4 *)(this + 0x24),2);
    snprintf(acStack_20,0x10,"/dev/uart/%d");
    iVar1 = open(acStack_20,0x4002);
    *(int *)(this + 0x4c) = iVar1;
    iVar1 = iVar1 >> 0x1f;
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","InitUart",0x108);
  }
  return iVar1;
}

