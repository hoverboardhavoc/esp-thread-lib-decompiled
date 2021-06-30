/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleWaitingResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleWaitingResponse(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint32_t aCommand, spinel_prop_key_t aKey, uint8_t * aBuffer, uint16_t aLength) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleWaitingResponse
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this,uint32_t aCommand,spinel_prop_key_t aKey,uint8_t *aBuffer,uint16_t aLength)

{
  otError oVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined2 in_register_0000203a;
  undefined4 *puVar5;
  int *piVar6;
  code *pcStack_18;
  spinel_status_t status;
  
  uVar3 = CONCAT22(in_register_0000203a,aLength);
  if (aKey == 0) {
    iVar2 = spinel_datatype_unpack(uVar3,&_LC14,&pcStack_18);
    if (iVar2 < 1) {
      this->mError = OT_ERROR_PARSE;
    }
    else {
      pcVar4 = pcStack_18;
      switch(pcStack_18) {
      case (code *)0x0:
      case (code *)0x1:
        break;
      case (code *)0x2:
        pcVar4 = (code *)0xc;
        break;
      case (code *)0x3:
        pcVar4 = (code *)0x7;
        break;
      case (code *)0x4:
        pcVar4 = (code *)0xd;
        break;
      default:
        pcVar4 = pcStack_18 + -0x4000;
        if (ThreadDatasetHandler < pcVar4) {
          pcVar4 = (code *)0x1;
        }
        break;
      case (code *)0x9:
        pcVar4 = (code *)0x6;
        break;
      case (code *)0xb:
        pcVar4 = (code *)0x3;
        break;
      case (code *)0xc:
        pcVar4 = (code *)0x5;
        break;
      case (code *)0xd:
      case (code *)0x14:
        pcVar4 = (code *)0x17;
        break;
      case (code *)0xe:
        pcVar4 = (code *)0x2;
        break;
      case (code *)0x11:
        pcVar4 = (code *)0xe;
        break;
      case (code *)0x12:
        pcVar4 = (code *)0xf;
        break;
      case (code *)0x13:
        pcVar4 = (code *)0x18;
      }
      this->mError = (otError)pcVar4;
    }
  }
  else if (aKey == 0x3bc0) {
    if ((this->mDiagOutput != (char *)0x0) &&
       (iVar2 = spinel_datatype_unpack_in_place(uVar3,&_LC27,&this->mDiagOutputMaxLen), iVar2 < 1))
    {
      this->mError = OT_ERROR_PARSE;
    }
  }
  else if (this->mWaitingKey == aKey) {
    if (this->mPropertyFormat == (char *)0x0) {
      if (this->mExpectedCommand == aCommand) {
        this->mError = OT_ERROR_NONE;
      }
      else {
        this->mError = OT_ERROR_DROP;
      }
    }
    else {
      if (*this->mPropertyFormat == '.') {
        puVar5 = (undefined4 *)this->mPropertyArgs;
        this->mPropertyArgs = puVar5 + 2;
        pcStack_18 = (code *)*puVar5;
        status = puVar5[1];
        if (pcStack_18 != (code *)0x0) {
          piVar6 = (int *)((int)&this->mInstance + status);
          pcVar4 = pcStack_18;
          if (((uint)pcStack_18 & 1) != 0) {
            pcVar4 = *(code **)(pcStack_18 + *piVar6 + -1);
          }
          oVar1 = (*pcVar4)(piVar6,aBuffer,uVar3,pcVar4);
          this->mError = oVar1;
          goto _L0;
        }
        __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x31b,
                      "void ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::HandleWaitingResponse(uint32_t, spinel_prop_key_t, const uint8_t*, uint16_t) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; uint32_t = long unsigned int; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; uint16_t = short unsigned int]"
                      ,"handler != nullptr");
      }
      iVar2 = spinel_datatype_vunpack_in_place(uVar3,this->mPropertyArgs);
      if (iVar2 < 1) {
        this->mError = OT_ERROR_PARSE;
      }
      else {
        this->mError = OT_ERROR_NONE;
      }
    }
  }
  else {
    this->mError = OT_ERROR_DROP;
  }
_L0:
  if (this->mError != OT_ERROR_NONE) {
    uVar3 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing result",uVar3);
  }
  return;
}

