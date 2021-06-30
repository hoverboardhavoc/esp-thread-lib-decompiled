/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetTransmitPower
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   GetTransmitPower(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, int8_t * aPower) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
GetTransmitPower(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                 *this,int8_t *aPower)

{
  otError oVar1;
  undefined4 uVar2;
  
  oVar1 = Get(this,0x25,"c");
  if (oVar1 != OT_ERROR_NONE) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Get transmit power failed",uVar2);
  }
  return oVar1;
}

