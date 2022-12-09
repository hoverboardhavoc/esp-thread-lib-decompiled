/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioGetTransmitBuffer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * otPlatRadioGetTransmitBuffer(void)

{
  return &s_radio;
}

