/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetWithParam
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   GetWithParam(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, spinel_prop_key_t aKey, uint8_t * aParam, spinel_size_t aParamSize, char * aFormat, ...)
    */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
GetWithParam(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
             *this,spinel_prop_key_t aKey,uint8_t *aParam,spinel_size_t aParamSize,char *aFormat,...
            )

{
  otError oVar1;
  RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this_00;
  undefined4 uVar2;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint uVar3;
  undefined4 in_a5;
  uint uVar4;
  uint uVar5;
  otError oVar6;
  undefined4 in_a6;
  undefined4 in_a7;
  otError oVar7;
  uint8_t auStack_50 [8];
  uint uStack_48;
  int iStack_44;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (this->mWaitingTid == '\0') {
    this->mPropertyArgs = &uStack_c;
    oVar1 = RequestWithPropertyFormat(this,aFormat,2,aKey,"D");
    return oVar1;
  }
  this_00 = (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *)
            __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x611,
                          "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::GetWithParam(spinel_prop_key_t, const uint8_t*, spinel_size_t, const char*, ...) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; spinel_size_t = unsigned int]"
                          ,"mWaitingTid == 0");
  uStack_48 = 0;
  iStack_44 = 0;
  if ((*(uint *)&this_00->field_0x704 >> 3 & 1) != 0) {
    oVar1 = otPlatTimeGet();
    uVar4 = *(uint *)((int)&this_00->mRadioTimeRecalcStart + 4);
    if ((extraout_a1 < uVar4) ||
       ((uVar4 == extraout_a1 && (oVar1 < (otError)this_00->mRadioTimeRecalcStart)))) {
      oVar7 = OT_ERROR_NONE;
      goto _L0;
    }
  }
  oVar1 = spinel_datatype_pack(auStack_50,8,&_LC35,uStack_48,iStack_44);
  if (oVar1 - OT_ERROR_FAILED < 8) {
    uVar4 = otPlatTimeGet();
    oVar7 = GetWithParam(this_00,0x802,auStack_50,oVar1,"X");
    oVar1 = otPlatTimeGet();
    if (oVar7 == OT_ERROR_NONE) {
      uVar3 = oVar1 >> 1 | extraout_a1_01 << 0x1f;
      uVar4 = (uVar4 >> 1 | extraout_a1_00 << 0x1f) + uVar3;
      uVar5 = uStack_48 - uVar4;
      *(uint *)&this_00->mRadioTimeOffset = uVar5;
      *(uint *)((int)&this_00->mRadioTimeOffset + 4) =
           (iStack_44 - ((uint)(uVar4 < uVar3) + (extraout_a1_00 >> 1) + (extraout_a1_01 >> 1))) -
           (uint)(uStack_48 < uVar5);
      this_00->field_0x704 = this_00->field_0x704 | 8;
      oVar6 = oVar1 + 60000000;
      oVar1 = (oVar6 < oVar1) + extraout_a1_01;
      *(otError *)&this_00->mRadioTimeRecalcStart = oVar6;
      *(otError *)((int)&this_00->mRadioTimeRecalcStart + 4) = oVar1;
    }
    else {
      *(otError *)&this_00->mRadioTimeRecalcStart = oVar1;
      *(uint *)((int)&this_00->mRadioTimeRecalcStart + 4) = extraout_a1_01;
    }
  }
  else {
    oVar7 = OT_ERROR_NO_BUFS;
  }
_L0:
  if (oVar7 != OT_ERROR_NONE) {
    uVar2 = otThreadErrorToString(oVar7);
    oVar1 = otLogWarn(0xc,_LC2,"%s: %s","Error calculating RCP time offset: %s",uVar2);
  }
  return oVar1;
}

