/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ProcessRadioStateMachine
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   ProcessRadioStateMachine(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
ProcessRadioStateMachine
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this)

{
  uint uVar1;
  int extraout_a0;
  uint extraout_a1;
  otRadioFrame *aAckFrame;
  char cVar2;
  uint uVar3;
  
  if (this->mState == kStateTransmitDone) {
    this->mState = kStateReceive;
    *(undefined4 *)&this->mTxRadioEndUs = 0xffffffff;
    *(undefined4 *)((int)&this->mTxRadioEndUs + 4) = 0xffffffff;
    if ((this->mAckRadioFrame).mLength == 0) {
      aAckFrame = (otRadioFrame *)0x0;
    }
    else {
      aAckFrame = &this->mAckRadioFrame;
    }
    TransmitDone(this,this->mTransmitFrame,aAckFrame,this->mTxError);
  }
  else if (this->mState == kStateTransmitting) {
    uVar1 = otPlatTimeGet();
    uVar3 = *(uint *)((int)&this->mTxRadioEndUs + 4);
    if ((uVar3 <= extraout_a1) && ((uVar3 != extraout_a1 || ((uint)this->mTxRadioEndUs <= uVar1))))
    {
      otLogWarn(0xc,_LC2,"radio tx timeout");
      HandleRcpTimeout(this);
      uVar1 = (uint)*(byte *)(extraout_a0 + 0x462);
      if (((int)(uint)*(ushort *)(extraout_a0 + 0x460) >> (uVar1 & 0x1f) & 1U) == 0) {
        if (uVar1 < 0xf) {
          cVar2 = *(byte *)(extraout_a0 + 0x462) + 1;
        }
        else {
          cVar2 = '\x01';
        }
        *(char *)(extraout_a0 + 0x462) = cVar2;
        *(ushort *)(extraout_a0 + 0x460) =
             *(ushort *)(extraout_a0 + 0x460) | (ushort)(1 << (uVar1 & 0x1f));
      }
      return;
    }
  }
  return;
}

