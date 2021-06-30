/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ParseRadioFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000129cc) */
/* WARNING: Removing unreachable block (ram,0x000129d4) */
/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   ParseRadioFrame(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, otRadioFrame * aFrame, uint8_t * aBuffer, uint16_t aLength, spinel_ssize_t * aUnpacked)
    */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
ParseRadioFrame(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                *this,otRadioFrame *aFrame,uint8_t *aBuffer,uint16_t aLength,
               spinel_ssize_t *aUnpacked)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 in_register_00002036;
  otError oStack_2c;
  uint receiveError;
  spinel_size_t size;
  int8_t noiseFloor;
  uint16_t flags;
  
  iVar2 = CONCAT22(in_register_00002036,aLength);
  size._2_2_ = 0;
  size._1_1_ = 0x80;
  receiveError = 0x7f;
  oStack_2c = OT_ERROR_NONE;
  if (iVar2 == 0) {
    aFrame->mLength = 0;
    oStack_2c = OT_ERROR_NONE;
  }
  else {
    uVar1 = spinel_datatype_unpack_in_place
                      (aBuffer,iVar2,"dccSt(CCX)t(i)",aFrame->mPsdu,&receiveError,
                       (undefined1 *)((int)&aFrame->mInfo + 0xd),(int)&size + 1,(int)&size + 2);
    if ((int)uVar1 < 1) {
      oStack_2c = OT_ERROR_PARSE;
    }
    else {
      *aUnpacked = uVar1;
      if ((this->mRadioCaps & 0x20) != 0) {
        iVar2 = spinel_datatype_unpack_in_place
                          (aBuffer + uVar1,iVar2 - (uVar1 & 0xffff) & 0xffff,"t(CL)",
                           (undefined1 *)((int)&aFrame->mInfo + 0xc),
                           (undefined1 *)((int)&aFrame->mInfo + 8));
        if (iVar2 < 1) {
          oStack_2c = OT_ERROR_PARSE;
          goto _L0;
        }
        *aUnpacked = iVar2 + *aUnpacked;
      }
      aFrame->mLength = (ushort)(byte)receiveError;
      (aFrame->mInfo).field2[0xf] =
           (aFrame->mInfo).field2[0xf] & 0xfc | (byte)(size._2_2_ >> 4) & 1 |
           (byte)((size._2_2_ >> 5 & 1) << 1);
    }
  }
_L0:
  if (oStack_2c != OT_ERROR_NONE) {
    uVar3 = otThreadErrorToString(oStack_2c);
    otLogWarn(0xc,_LC2,"%s: %s","Handle radio frame failed",uVar3);
  }
  return oStack_2c;
}

