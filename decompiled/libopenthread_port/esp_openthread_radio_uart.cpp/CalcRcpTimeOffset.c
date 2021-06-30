/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CalcRcpTimeOffset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   CalcRcpTimeOffset(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
CalcRcpTimeOffset(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                  *this)

{
  uint uVar1;
  spinel_size_t aParamSize;
  undefined4 uVar2;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  otError oVar6;
  uint8_t auStack_30 [4];
  uint8_t buffer [8];
  uint64_t remoteTimestamp;
  
  buffer[4] = '\0';
  buffer[5] = '\0';
  buffer[6] = '\0';
  buffer[7] = '\0';
  if ((*(uint *)&this->field_0x704 >> 3 & 1) != 0) {
    uVar1 = otPlatTimeGet();
    uVar4 = *(uint *)((int)&this->mRadioTimeRecalcStart + 4);
    if ((extraout_a1 < uVar4) ||
       ((uVar4 == extraout_a1 && (uVar1 < (uint)this->mRadioTimeRecalcStart)))) {
      oVar6 = OT_ERROR_NONE;
      goto _L0;
    }
  }
  aParamSize = spinel_datatype_pack(auStack_30,8,&_LC35,buffer._4_4_,0);
  if (aParamSize - 1 < 8) {
    uVar1 = otPlatTimeGet();
    oVar6 = GetWithParam(this,0x802,auStack_30,aParamSize,"X");
    uVar4 = otPlatTimeGet();
    if (oVar6 == OT_ERROR_NONE) {
      uVar3 = uVar4 >> 1 | extraout_a1_01 << 0x1f;
      uVar1 = (uVar1 >> 1 | extraout_a1_00 << 0x1f) + uVar3;
      uVar5 = buffer._4_4_ - uVar1;
      *(uint *)&this->mRadioTimeOffset = uVar5;
      *(uint *)((int)&this->mRadioTimeOffset + 4) =
           -(uint)((uint)buffer._4_4_ < uVar5) -
           ((uint)(uVar1 < uVar3) + (extraout_a1_00 >> 1) + (extraout_a1_01 >> 1));
      this->field_0x704 = this->field_0x704 | 8;
      *(uint *)&this->mRadioTimeRecalcStart = uVar4 + 60000000;
      *(uint *)((int)&this->mRadioTimeRecalcStart + 4) = (uVar4 + 60000000 < uVar4) + extraout_a1_01
      ;
    }
    else {
      *(uint *)&this->mRadioTimeRecalcStart = uVar4;
      *(uint *)((int)&this->mRadioTimeRecalcStart + 4) = extraout_a1_01;
    }
  }
  else {
    oVar6 = OT_ERROR_NO_BUFS;
  }
_L0:
  if (oVar6 != OT_ERROR_NONE) {
    uVar2 = otThreadErrorToString(oVar6);
    otLogWarn(0xc,_LC2,"%s: %s","Error calculating RCP time offset: %s",uVar2);
  }
  return;
}

