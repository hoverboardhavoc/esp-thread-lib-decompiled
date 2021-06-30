/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   Enable(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, otInstance * aInstance) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Enable(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
      otInstance *aInstance)

{
  otError oVar1;
  undefined4 uVar2;
  
  if (this->mState != kStateDisabled) {
    return OT_ERROR_NONE;
  }
  this->mInstance = aInstance;
  oVar1 = Set(this,0x20,"b");
  if ((((oVar1 == OT_ERROR_NONE) && (oVar1 = Set(this,0x36,"S"), oVar1 == OT_ERROR_NONE)) &&
      (oVar1 = Set(this,0x35,"S"), oVar1 == OT_ERROR_NONE)) &&
     (oVar1 = Get(this,0x27,"c"), oVar1 == OT_ERROR_NONE)) {
    this->mState = kStateSleep;
  }
  if (oVar1 != OT_ERROR_NONE) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"RadioSpinel enable: %s",uVar2);
    oVar1 = OT_ERROR_FAILED;
  }
  return oVar1;
}

