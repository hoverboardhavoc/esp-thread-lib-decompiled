/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryRecoverUart
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: esp_err_t TryRecoverUart(UartSpinelInterface * this) */

esp_err_t __thiscall esp::openthread::UartSpinelInterface::TryRecoverUart(UartSpinelInterface *this)

{
  esp_err_t eVar1;
  undefined4 uVar2;
  
  eVar1 = DeinitUart(this);
  if (eVar1 == 0) {
    eVar1 = InitUart(this,&this->m_uart_config);
    if (eVar1 != 0) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","TryRecoverUart",0x122);
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&::_L0,uVar2,"OPENTHREAD","TryRecoverUart",0x121);
  }
  return eVar1;
}

