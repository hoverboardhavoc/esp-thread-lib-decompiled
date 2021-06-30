/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: esp_err_t Init(UartSpinelInterface * this, esp_openthread_uart_config_t
   * radio_uart_config) */

esp_err_t __thiscall
esp::openthread::UartSpinelInterface::Init
          (UartSpinelInterface *this,esp_openthread_uart_config_t *radio_uart_config)

{
  uint8_t *puVar1;
  esp_err_t eVar2;
  
  puVar1 = (uint8_t *)heap_caps_malloc(0x400,4);
  this->m_uart_rx_buffer = puVar1;
  if (puVar1 == (uint8_t *)0x0) {
    eVar2 = 0x101;
  }
  else {
    eVar2 = InitUart(this,radio_uart_config);
  }
  return eVar2;
}

