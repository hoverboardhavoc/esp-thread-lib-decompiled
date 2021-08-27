/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryRecoverUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::TryRecoverUart() */

int __thiscall esp::openthread::UartSpinelInterface::TryRecoverUart(UartSpinelInterface *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DeinitUart(this);
  if (iVar1 == 0) {
    iVar1 = InitUart(this,(esp_openthread_uart_config_t *)(this + 0x24));
    if (iVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","TryRecoverUart",0x120);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&::_L0,uVar2,"OPENTHREAD","TryRecoverUart",0x11f);
  }
  return iVar1;
}

