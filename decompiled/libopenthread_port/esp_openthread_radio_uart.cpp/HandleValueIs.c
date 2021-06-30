/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleValueIs
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleValueIs(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, spinel_prop_key_t aKey, uint8_t * aBuffer, uint16_t aLength) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleValueIs(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
              *this,spinel_prop_key_t aKey,uint8_t *aBuffer,uint16_t aLength)

{
  otError oVar1;
  undefined4 uVar2;
  undefined2 in_register_00002036;
  int iVar3;
  uint local_c0;
  uint8_t scanChannel;
  spinel_status_t status;
  uint uStack_24;
  spinel_ssize_t unpacked;
  
  iVar3 = CONCAT22(in_register_00002036,aLength);
  if (aKey == 0x71) {
    oVar1 = ParseRadioFrame(this,&this->mRxRadioFrame,aBuffer,aLength,(spinel_ssize_t *)&uStack_24);
    if (oVar1 == OT_ERROR_NONE) {
      RadioReceive(this);
    }
  }
  else if (aKey == 0) {
    _scanChannel = 0;
    uStack_24 = spinel_datatype_unpack(aBuffer,iVar3,&_LC14,&scanChannel);
    if ((int)uStack_24 < 1) {
      oVar1 = OT_ERROR_PARSE;
    }
    else {
      oVar1 = OT_ERROR_NONE;
      if (_scanChannel - 0x70 < 0x11) {
        if (this->mState == kStateDisabled) {
          uVar2 = spinel_status_to_cstr();
          otLogInfo(0xc,_LC2,"RCP reset: %s",uVar2);
          this->field_0x704 = this->field_0x704 | 2;
          goto _L0;
        }
        HandleRcpUnexpectedReset(this,_scanChannel);
      }
      uVar2 = spinel_status_to_cstr();
      otLogInfo(0xc,_LC2,"RCP last status: %s",uVar2);
    }
  }
  else if (aKey == 0x39) {
    uStack_24 = spinel_datatype_unpack(aBuffer,iVar3,&_LC64,&local_c0,&scanChannel);
    if ((int)uStack_24 < 1) {
      oVar1 = OT_ERROR_PARSE;
    }
    else {
      otPlatRadioEnergyScanDone(this->mInstance,(int)(char)scanChannel);
      oVar1 = OT_ERROR_NONE;
    }
  }
  else if (aKey == 0x70) {
    local_c0 = 0x97;
    uStack_24 = spinel_datatype_unpack_in_place(aBuffer,iVar3,&_LC13,&scanChannel,&local_c0);
    if (local_c0 < 0x97) {
      if (0 < (int)uStack_24) {
        oVar1 = OT_ERROR_NONE;
        goto _L0;
      }
    }
    else {
      __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x375,
                    "void ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::HandleValueIs(spinel_prop_key_t, const uint8_t*, uint16_t) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; uint16_t = short unsigned int]"
                    ,"len < sizeof(logStream)");
    }
    oVar1 = OT_ERROR_PARSE;
  }
  else if (aKey == 0x74) {
    if ((*(uint *)&this->field_0x704 >> 2 & 1) == 0) {
      oVar1 = OT_ERROR_NONE;
    }
    else {
      uStack_24 = spinel_datatype_unpack(aBuffer,iVar3,&_LC27,&scanChannel);
      if (((int)uStack_24 < 0) ||
         (uStack_24 = spinel_datatype_unpack
                                (aBuffer + uStack_24,iVar3 - (uStack_24 & 0xffff) & 0xffff,&_LC38,
                                 &local_c0), (int)uStack_24 < 1)) {
        oVar1 = OT_ERROR_PARSE;
      }
      else {
        switch(local_c0 & 0xff) {
        case 0:
        case 1:
        case 2:
          otLogCrit(0xc,_LC2,"RCP => %s",_scanChannel);
          break;
        case 3:
        case 4:
          otLogWarn(0xc,_LC2,"RCP => %s",_scanChannel);
          break;
        case 5:
          otLogNote(0xc,_LC2,"RCP => %s",_scanChannel);
          break;
        case 6:
          otLogInfo(0xc,_LC2,"RCP => %s",_scanChannel);
        }
        oVar1 = OT_ERROR_NONE;
      }
    }
  }
  else {
    oVar1 = OT_ERROR_NONE;
  }
_L0:
  if (oVar1 != OT_ERROR_NONE) {
    uVar2 = otThreadErrorToString(oVar1);
    otLogWarn(0xc,_LC2,"%s: %s","Failed to handle ValueIs",uVar2);
  }
  return;
}

