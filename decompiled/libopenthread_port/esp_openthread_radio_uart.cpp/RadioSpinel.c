/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RadioSpinel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   RadioSpinel(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
RadioSpinel(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
            *this)

{
  undefined1 *puVar1;
  
  this->mInstance = (otInstance *)0x0;
  (this->mRxFrameBuffer).mWriteFrameStart =
       &(this->mRxFrameBuffer).super_FrameWritePointer.field_0x6;
  puVar1 = &(this->mRxFrameBuffer).field_0xa;
  (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar1;
  (this->mRxFrameBuffer).field_0x8 = 0;
  (this->mRxFrameBuffer).field_0x9 = 0;
  (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength =
       ((short)this + 0x40a) - (short)puVar1;
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            (&this->mSpinelInterface,HandleReceivedFrame,this,
             (MultiFrameBuffer *)&this->mRxFrameBuffer);
  this->mCmdTidsInUse = 0;
  this->mCmdNextTid = '\x01';
  this->mTxRadioTid = '\0';
  this->mWaitingTid = '\0';
  this->mWaitingKey = 0;
  this->mPropertyFormat = (char *)0x0;
  this->mExpectedCommand = 0;
  this->mError = OT_ERROR_NONE;
  this->mTransmitFrame = (otRadioFrame *)0x0;
  this->mShortAddress = 0;
  this->mPanId = 0xffff;
  this->mRadioCaps = '\0';
  this->mChannel = '\0';
  this->mRxSensitivity = '\0';
  this->mState = kStateDisabled;
  this->field_0x704 = this->field_0x704 & 0xf0;
  this->mDiagMode = false;
  this->mDiagOutput = (char *)0x0;
  this->mDiagOutputMaxLen = 0;
  *(undefined4 *)&this->mTxRadioEndUs = 0xffffffff;
  *(undefined4 *)((int)&this->mTxRadioEndUs + 4) = 0xffffffff;
  *(undefined4 *)&this->mRadioTimeRecalcStart = 0xffffffff;
  *(undefined4 *)((int)&this->mRadioTimeRecalcStart + 4) = 0xffffffff;
  *(undefined4 *)&this->mRadioTimeOffset = 0;
  *(undefined4 *)((int)&this->mRadioTimeOffset + 4) = 0;
  memset(&this->mMaxPowerTable,0x1e,0x10);
  this->mVersion[0] = '\0';
  return;
}

