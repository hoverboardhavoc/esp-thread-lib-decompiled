/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleTransmitDone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleTransmitDone(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint32_t aCommand, spinel_prop_key_t aKey, uint8_t * aBuffer, uint16_t aLength) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleTransmitDone(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this,uint32_t aCommand,spinel_prop_key_t aKey,uint8_t *aBuffer,uint16_t aLength)

{
  otError oVar1;
  otError oVar2;
  undefined4 uVar3;
  undefined2 in_register_0000203a;
  uint uVar4;
  uint uVar5;
  uint8_t *puVar6;
  otError oVar7;
  undefined1 uStack_31;
  undefined1 auStack_30 [3];
  uint8_t keyId;
  uint32_t frameCounter;
  spinel_ssize_t unpacked;
  otError oStack_24;
  bool framePending;
  spinel_status_t status;
  
  oStack_24 = OT_ERROR_NONE;
  unpacked._3_1_ = 0;
  if (aCommand == 6) {
    if (aKey == 0) {
      frameCounter = spinel_datatype_unpack
                               (aBuffer,CONCAT22(in_register_0000203a,aLength),&_LC14,
                                &stack0xffffffdc);
      oVar1 = OT_ERROR_PARSE;
      oVar2 = oVar1;
      if (0 < (int)frameCounter) {
        puVar6 = aBuffer + frameCounter;
        uVar4 = CONCAT22(in_register_0000203a,aLength) - (frameCounter & 0xffff) & 0xffff;
        frameCounter = spinel_datatype_unpack(puVar6,uVar4,&_LC39,(int)&unpacked + 3);
        if (0 < (int)frameCounter) {
          puVar6 = puVar6 + frameCounter;
          uVar4 = uVar4 - (frameCounter & 0xffff);
          uVar5 = uVar4 & 0xffff;
          if (oStack_24 == OT_ERROR_NONE) {
            oVar2 = ParseRadioFrame(this,&this->mAckRadioFrame,puVar6,(uint16_t)uVar4,
                                    (spinel_ssize_t *)&frameCounter);
            if (oVar2 != OT_ERROR_NONE) goto _L0;
            puVar6 = puVar6 + frameCounter;
            uVar5 = uVar5 - (frameCounter & 0xffff) & 0xffff;
            oVar7 = oVar2;
          }
          else {
            oVar7 = oStack_24;
            switch(oStack_24) {
            case OT_ERROR_FAILED:
              break;
            case OT_ERROR_DROP:
              oVar7 = OT_ERROR_NOT_IMPLEMENTED;
              break;
            case OT_ERROR_NO_BUFS:
              oVar7 = OT_ERROR_INVALID_ARGS;
              break;
            case OT_ERROR_NO_ROUTE:
              oVar7 = OT_ERROR_INVALID_STATE;
              break;
            default:
              oVar7 = oStack_24 - 0x4000;
              if (0x10000 < oStack_24 - 0x4000) {
                oVar7 = OT_ERROR_FAILED;
              }
              break;
            case OT_ERROR_ADDRESS_QUERY:
              oVar7 = oVar1;
              break;
            case OT_ERROR_ABORT:
              oVar7 = OT_ERROR_NO_BUFS;
              break;
            case OT_ERROR_NOT_IMPLEMENTED:
              oVar7 = OT_ERROR_BUSY;
              break;
            case OT_ERROR_INVALID_STATE:
            case OT_ERROR_INVALID_SOURCE_ADDRESS:
              oVar7 = OT_ERROR_NOT_FOUND;
              break;
            case OT_ERROR_NO_ACK:
              oVar7 = OT_ERROR_DROP;
              break;
            case OT_ERROR_FCS:
              oVar7 = OT_ERROR_NO_ACK;
              break;
            case OT_ERROR_NO_FRAME_RECEIVED:
              oVar7 = OT_ERROR_CHANNEL_ACCESS_FAILURE;
              break;
            case OT_ERROR_UNKNOWN_NEIGHBOR:
              oVar7 = OT_ERROR_ALREADY;
            }
          }
          oVar2 = oVar7;
          if ((((this->mRadioCaps & 0x20) != 0) && ((*this->mTransmitFrame->mPsdu & 8) != 0)) &&
             (frameCounter = spinel_datatype_unpack(puVar6,uVar5,&_LC56,&uStack_31,auStack_30),
             oVar2 = oVar1, 0 < (int)frameCounter)) {
            ot::Mac::Frame::SetKeyId((uchar)this->mTransmitFrame);
            ot::Mac::Frame::SetFrameCounter((ulong)this->mTransmitFrame);
            oVar2 = oVar7;
          }
        }
      }
    }
    else {
      oVar2 = OT_ERROR_FAILED;
    }
  }
  else {
    oVar2 = OT_ERROR_FAILED;
  }
_L0:
  this->mState = kStateTransmitDone;
  this->mTxError = oVar2;
  if (oVar2 != OT_ERROR_NONE) {
    uVar3 = otThreadErrorToString(oVar2);
    otLogWarn(0xc,_LC2,"%s: %s","Handle transmit done failed",uVar3);
  }
  return;
}

