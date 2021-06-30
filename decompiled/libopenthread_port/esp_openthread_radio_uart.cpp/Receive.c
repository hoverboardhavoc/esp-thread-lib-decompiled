/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   Receive(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, uint8_t aChannel) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Receive(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
       uint8_t aChannel)

{
  otError oVar1;
  undefined3 in_register_0000202d;
  
  if (this->mState == kStateDisabled) {
    return OT_ERROR_INVALID_STATE;
  }
  if ((uint)this->mChannel != CONCAT31(in_register_0000202d,aChannel)) {
    oVar1 = Set(this,0x21,"C");
    if (oVar1 != OT_ERROR_NONE) {
      return oVar1;
    }
    this->mChannel = aChannel;
  }
  oVar1 = OT_ERROR_NONE;
  if ((this->mState != kStateSleep) || (oVar1 = Set(this,0x37,"b"), oVar1 == OT_ERROR_NONE)) {
    if (this->mTxRadioTid != 0) {
      this->mCmdTidsInUse = ~(ushort)(1 << (this->mTxRadioTid & 0x1f)) & this->mCmdTidsInUse;
      this->mTxRadioTid = '\0';
    }
    this->mState = kStateReceive;
  }
  return oVar1;
}

