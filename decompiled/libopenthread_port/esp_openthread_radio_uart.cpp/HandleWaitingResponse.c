/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleWaitingResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleWaitingResponse(unsigned long, unsigned long, unsigned
   char const*, unsigned short) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleWaitingResponse
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          ,ulong param_1,ulong param_2,uchar *param_3,ushort param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined2 in_register_0000203a;
  undefined4 *puVar4;
  code *pcStack_18;
  int iStack_14;
  
  uVar2 = CONCAT22(in_register_0000203a,param_4);
  if (param_2 != 0) {
    if (param_2 == 0x3bc0) {
      if ((*(int *)(this + 0x708) != 0) &&
         (iVar1 = spinel_datatype_unpack_in_place(uVar2,&_LC27,this + 0x70c), iVar1 < 1)) {
        *(undefined4 *)(this + 0x478) = 6;
      }
    }
    else if (*(ulong *)(this + 0x468) == param_2) {
      if (*(char **)(this + 0x46c) == (char *)0x0) {
        if (*(ulong *)(this + 0x474) == param_1) {
          *(undefined4 *)(this + 0x478) = 0;
        }
        else {
          *(undefined4 *)(this + 0x478) = 2;
        }
      }
      else {
        if (**(char **)(this + 0x46c) == '.') {
          puVar4 = *(undefined4 **)(this + 0x470);
          *(undefined4 **)(this + 0x470) = puVar4 + 2;
          pcStack_18 = (code *)*puVar4;
          iStack_14 = puVar4[1];
          if (pcStack_18 != (code *)0x0) {
            pcVar3 = pcStack_18;
            if (((uint)pcStack_18 & 1) != 0) {
              pcVar3 = *(code **)(pcStack_18 + *(int *)(this + iStack_14) + -1);
            }
            uVar2 = (*pcVar3)(this + iStack_14,param_3,uVar2,pcVar3);
            *(undefined4 *)(this + 0x478) = uVar2;
            goto _L0;
          }
          __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                        0x31b,
                        "void ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::HandleWaitingResponse(uint32_t, spinel_prop_key_t, const uint8_t*, uint16_t) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; uint32_t = long unsigned int; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; uint16_t = short unsigned int]"
                        ,"handler != nullptr");
        }
        iVar1 = spinel_datatype_vunpack_in_place(uVar2,*(undefined4 *)(this + 0x470));
        if (iVar1 < 1) {
          *(undefined4 *)(this + 0x478) = 6;
        }
        else {
          *(undefined4 *)(this + 0x478) = 0;
        }
      }
    }
    else {
      *(undefined4 *)(this + 0x478) = 2;
    }
    goto _L0;
  }
  iVar1 = spinel_datatype_unpack(uVar2,&_LC14,&pcStack_18);
  if (iVar1 < 1) {
    *(undefined4 *)(this + 0x478) = 6;
    goto _L0;
  }
  if (pcStack_18 == (code *)0xb) {
    pcVar3 = (code *)0x3;
  }
  else if (pcStack_18 < (code *)0xc) {
    if (pcStack_18 == (code *)0x2) {
      pcVar3 = (code *)0xc;
    }
    else if (pcStack_18 < (code *)0x3) {
      pcVar3 = pcStack_18;
      if ((pcStack_18 != (code *)0x0) && (pcStack_18 != (code *)0x1)) {
_L0:
        pcVar3 = pcStack_18 + -0x4000;
        if (ThreadDatasetHandler < pcStack_18 + -0x4000) {
          pcVar3 = (code *)0x1;
        }
      }
    }
    else if (pcStack_18 == (code *)0x4) {
      pcVar3 = (code *)0xd;
    }
    else if (pcStack_18 < (code *)0x4) {
      pcVar3 = (code *)0x7;
    }
    else {
      if (pcStack_18 != (code *)0x9) goto _L0;
      pcVar3 = (code *)0x6;
    }
  }
  else if (pcStack_18 == (code *)0x11) {
    pcVar3 = (code *)0xe;
  }
  else if (pcStack_18 < (code *)0x12) {
    if (pcStack_18 == (code *)0xd) {
      pcVar3 = (code *)0x17;
    }
    else if (pcStack_18 < (code *)0xd) {
      pcVar3 = (code *)0x5;
    }
    else {
      if (pcStack_18 != (code *)0xe) goto _L0;
      pcVar3 = (code *)0x2;
    }
  }
  else if (pcStack_18 == (code *)0x13) {
    pcVar3 = (code *)0x18;
  }
  else if (pcStack_18 < (code *)0x13) {
    pcVar3 = (code *)0xf;
  }
  else {
    if (pcStack_18 != (code *)0x14) goto _L0;
    pcVar3 = (code *)0x17;
  }
  *(code **)(this + 0x478) = pcVar3;
_L0:
  if (*(int *)(this + 0x478) != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing result",uVar2);
  }
  return;
}

