/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   Transmit(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, otRadioFrame * aFrame) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Transmit(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
        otRadioFrame *aFrame)

{
  otError oVar1;
  uint uVar2;
  int extraout_a1;
  
  if (this->mState != kStateReceive) {
    if (this->mState != kStateSleep) {
      return OT_ERROR_INVALID_STATE;
    }
    if ((this->mRadioCaps & 0x10) == 0) {
      return OT_ERROR_INVALID_STATE;
    }
  }
  this->mTransmitFrame = aFrame;
  otPlatRadioTxStarted(this->mInstance);
  oVar1 = Request(this,3,0x71,"dCCCbbbLL");
  if (oVar1 == OT_ERROR_NONE) {
    this->mState = kStateTransmitting;
    uVar2 = otPlatTimeGet();
    *(uint *)&this->mTxRadioEndUs = uVar2 + 5000000;
    *(uint *)((int)&this->mTxRadioEndUs + 4) = (uint)(uVar2 + 5000000 < uVar2) + extraout_a1;
  }
  return oVar1;
}

