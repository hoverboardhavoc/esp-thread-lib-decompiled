/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Disable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   Disable(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Disable(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this)

{
  State SVar1;
  otError oVar2;
  undefined4 uVar3;
  int __status;
  
  SVar1 = this->mState;
  if (SVar1 != kStateDisabled) {
    if (SVar1 == kStateSleep) {
      oVar2 = Set(this,0x20,"b",0);
      if (oVar2 != OT_ERROR_NONE) {
        oVar2 = Set(this,0x20,"b",0);
        if (oVar2 == OT_ERROR_INVALID_ARGS) {
          uVar3 = 2;
        }
        else {
          uVar3 = 1;
        }
        uVar3 = otExitCodeToString(uVar3);
        otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","Disable",
                  "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x7e8,
                  uVar3);
        oVar2 = Set(this,0x20,"b",0);
        if (oVar2 == OT_ERROR_INVALID_ARGS) {
          __status = 2;
        }
        else {
          __status = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      this->mState = kStateDisabled;
      this->mInstance = (otInstance *)0x0;
      SVar1 = kStateDisabled;
    }
    else {
      SVar1 = 0xd;
    }
  }
  return SVar1;
}

