/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleValueIs
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleValueIs(unsigned long, unsigned char const*, unsigned
   short) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleValueIs(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
              *this,ulong param_1,uchar *param_2,ushort param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 in_register_00002036;
  uint uVar3;
  uint local_c0;
  int aiStack_bc [38];
  uint auStack_24 [4];
  
  iVar1 = CONCAT22(in_register_00002036,param_3);
  if (param_1 == 0x71) {
    iVar1 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x600),param_2,param_3,(int *)auStack_24);
    if (iVar1 == 0) {
      RadioReceive(this);
    }
  }
  else if (param_1 == 0) {
    aiStack_bc[0] = 0;
    auStack_24[0] = spinel_datatype_unpack(param_2,iVar1,&_LC14,aiStack_bc);
    if ((int)auStack_24[0] < 1) {
      iVar1 = 6;
    }
    else {
      iVar1 = 0;
      if (aiStack_bc[0] - 0x70U < 0x11) {
        if (*(int *)(this + 0x700) == 0) {
          uVar2 = spinel_status_to_cstr();
          otLogInfo(0xc,_LC2,"RCP reset: %s",uVar2);
          this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         )((byte)this[0x704] | 2);
          goto _L0;
        }
        HandleRcpUnexpectedReset((ulong)this);
      }
      uVar2 = spinel_status_to_cstr();
      otLogInfo(0xc,_LC2,"RCP last status: %s",uVar2);
    }
  }
  else if (param_1 == 0x39) {
    auStack_24[0] = spinel_datatype_unpack(param_2,iVar1,&_LC64,&local_c0,aiStack_bc);
    if ((int)auStack_24[0] < 1) {
      iVar1 = 6;
    }
    else {
      otPlatRadioEnergyScanDone(*(undefined4 *)this,(int)(char)aiStack_bc[0]);
      iVar1 = 0;
    }
  }
  else if (param_1 == 0x70) {
    local_c0 = 0x97;
    auStack_24[0] = spinel_datatype_unpack_in_place(param_2,iVar1,&_LC13,aiStack_bc,&local_c0);
    if (local_c0 < 0x97) {
      if (0 < (int)auStack_24[0]) {
        iVar1 = 0;
        goto _L0;
      }
    }
    else {
      __assert_func("IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                    0x375,
                    "void ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::HandleValueIs(spinel_prop_key_t, const uint8_t*, uint16_t) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; uint16_t = short unsigned int]"
                    ,"len < sizeof(logStream)");
    }
    iVar1 = 6;
  }
  else if (param_1 == 0x74) {
    if ((*(uint *)(this + 0x704) >> 2 & 1) == 0) {
      iVar1 = 0;
    }
    else {
      auStack_24[0] = spinel_datatype_unpack(param_2,iVar1,&_LC27,aiStack_bc);
      if (-1 < (int)auStack_24[0]) {
        auStack_24[0] =
             spinel_datatype_unpack
                       (param_2 + auStack_24[0],iVar1 - (auStack_24[0] & 0xffff) & 0xffff,&_LC38,
                        &local_c0);
        if (0 < (int)auStack_24[0]) {
          uVar3 = local_c0 & 0xff;
          if (uVar3 < 5) {
            if (uVar3 < 3) {
              otLogCrit(0xc,_LC2,"RCP => %s",aiStack_bc[0]);
            }
            else {
              otLogWarn(0xc,_LC2,"RCP => %s",aiStack_bc[0]);
            }
          }
          else if (uVar3 == 5) {
            otLogNote(0xc,_LC2,"RCP => %s",aiStack_bc[0]);
          }
          else if (uVar3 == 6) {
            otLogInfo(0xc,_LC2,"RCP => %s",aiStack_bc[0]);
          }
          iVar1 = 0;
          goto _L0;
        }
      }
      iVar1 = 6;
    }
  }
  else {
    iVar1 = 0;
  }
_L0:
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString(iVar1);
    otLogWarn(0xc,_LC2,"%s: %s","Failed to handle ValueIs",uVar2);
  }
  return;
}

