/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetPanId
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   SetPanId(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, uint16_t aPanId) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
SetPanId(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
        uint16_t aPanId)

{
  otError oVar1;
  undefined2 in_register_0000202e;
  
  if ((uint)this->mPanId != CONCAT22(in_register_0000202e,aPanId)) {
    oVar1 = Set(this,0x36,"S");
    if (oVar1 == OT_ERROR_NONE) {
      this->mPanId = aPanId;
    }
    return oVar1;
  }
  return OT_ERROR_NONE;
}

