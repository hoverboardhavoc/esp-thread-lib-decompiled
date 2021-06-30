/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */

otError otPlatRadioAddSrcMatchShortEntry(otInstance *instance,uint16_t short_address)

{
  otError oVar1;
  
  oVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
          AddSrcMatchShortEntry(&s_radio,short_address);
  return oVar1;
}

