/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleResponse(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint8_t * aBuffer, uint16_t aLength) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleResponse(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
               *this,uint8_t *aBuffer,uint16_t aLength)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 in_register_00002032;
  uint uStack_24;
  uint32_t cmd;
  uint16_t uStack_1c;
  uint8_t header;
  spinel_size_t len;
  uint8_t *data;
  spinel_prop_key_t key;
  
  len = 0;
  _uStack_1c = 0;
  cmd._3_1_ = 0;
  uStack_24 = 0;
  iVar1 = spinel_datatype_unpack
                    (aBuffer,CONCAT22(in_register_00002032,aLength),&_LC58,(int)&cmd + 3,&uStack_24,
                     &data,&len,&uStack_1c);
  if (iVar1 < 1) {
    iVar1 = 6;
  }
  else if (uStack_24 < 6) {
    iVar1 = 6;
  }
  else if (uStack_24 < 9) {
    if (this->mWaitingTid == (cmd._3_1_ & 0xf)) {
      HandleWaitingResponse(this,uStack_24,(spinel_prop_key_t)data,(uint8_t *)len,uStack_1c);
      this->mCmdTidsInUse = ~(ushort)(1 << (this->mWaitingTid & 0x1f)) & this->mCmdTidsInUse;
      this->mWaitingTid = '\0';
      iVar1 = 0;
    }
    else if (this->mTxRadioTid == (cmd._3_1_ & 0xf)) {
      if (this->mState == kStateTransmitting) {
        HandleTransmitDone(this,uStack_24,(spinel_prop_key_t)data,(uint8_t *)len,uStack_1c);
      }
      this->mCmdTidsInUse = ~(ushort)(1 << (this->mTxRadioTid & 0x1f)) & this->mCmdTidsInUse;
      this->mTxRadioTid = '\0';
      iVar1 = 0;
    }
    else {
      otLogWarn(0xc,_LC2,"Unexpected Spinel transaction message: %u");
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 6;
  }
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing response",uVar2);
  }
  return;
}

