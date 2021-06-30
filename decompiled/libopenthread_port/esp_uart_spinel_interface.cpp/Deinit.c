/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: esp_err_t Deinit(UartSpinelInterface * this) */

esp_err_t __thiscall esp::openthread::UartSpinelInterface::Deinit(UartSpinelInterface *this)

{
  esp_err_t eVar1;
  
  if (this->m_uart_rx_buffer != (uint8_t *)0x0) {
    heap_caps_free();
  }
  this->m_uart_rx_buffer = (uint8_t *)0x0;
  eVar1 = DeinitUart(this);
  return eVar1;
}

