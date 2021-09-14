/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  int iVar3;
  undefined2 in_register_00002036;
  uint uVar4;
  int local_c0;
  uint local_bc;
  int aiStack_b8 [41];
  
  iVar1 = CONCAT22(in_register_00002036,param_3);
  if (param_1 == 0x71) {
    iVar1 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x600),param_2,param_3,&local_c0);
    if (iVar1 != 0) goto _L0;
    if (((*(uint *)(this + 0x704) & 1) != 0) || (1 < *(uint *)(this + 0x700))) {
      if (s_radio == '\0') {
        otPlatRadioReceiveDone(*(undefined4 *)this,(otRadioFrame *)(this + 0x600),0);
      }
      else {
        otPlatDiagRadioReceiveDone();
      }
      goto _L0;
    }
    goto _L0;
  }
  if (param_1 == 0) {
    aiStack_b8[0] = 0;
    local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC10,aiStack_b8);
    if (0 < local_c0) {
      iVar1 = 0;
      if (aiStack_b8[0] - 0x70U < 0x11) {
        if (*(int *)(this + 0x700) != 0) {
          uVar2 = spinel_status_to_cstr();
          _otLogCrit(0xc,"Unexpected RCP reset: %s",uVar2);
          uVar2 = otExitCodeToString(4);
          _otLogCrit(0xc,"%s() at %s:%d: %s","HandleRcpUnexpectedReset",
                     "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                     0x892,uVar2);
                    /* WARNING: Subroutine does not return */
          exit(4);
        }
        uVar2 = spinel_status_to_cstr();
        _otLogInfo(0xc,"RCP reset: %s",uVar2);
        this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       )((byte)this[0x704] | 2);
      }
      else {
        uVar2 = spinel_status_to_cstr();
        _otLogInfo(0xc,"RCP last status: %s",uVar2);
      }
      goto _L0;
    }
  }
  else if (param_1 == 0x39) {
    local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC58,&local_bc,aiStack_b8);
    if (0 < local_c0) {
      otPlatRadioEnergyScanDone(*(undefined4 *)this,(int)(char)aiStack_b8[0]);
      goto _L0;
    }
  }
  else {
    if (param_1 != 0x70) {
      if ((param_1 == 0x74) && ((*(uint *)(this + 0x704) >> 2 & 1) != 0)) {
        local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC23,aiStack_b8);
        if ((local_c0 < 0) ||
           (local_c0 = spinel_datatype_unpack
                                 (param_2 + local_c0,iVar1 - local_c0 & 0xffff,&_LC33,&local_bc),
           local_c0 < 1)) goto _L0;
        uVar4 = local_bc & 0xff;
        if (uVar4 < 5) {
          if (uVar4 < 3) {
            _otLogCrit(0xc,"RCP => %s",aiStack_b8[0]);
          }
          else {
            _otLogWarn(0xc,"RCP => %s");
          }
        }
        else if (uVar4 == 5) {
          _otLogNote(0xc,"RCP => %s",aiStack_b8[0]);
        }
        else if (uVar4 == 6) {
          _otLogInfo(0xc,"RCP => %s",aiStack_b8[0]);
        }
      }
_L0:
      iVar1 = 0;
      goto _L0;
    }
    local_bc = 0x97;
    iVar3 = spinel_datatype_unpack_in_place(param_2,iVar1,&_LC9,aiStack_b8,&local_bc);
    local_c0 = iVar3;
    if (0x96 < local_bc) {
      iVar3 = __assert_func(0,0,0,0);
    }
    iVar1 = 0;
    if (0 < iVar3) goto _L0;
  }
_L0:
  iVar1 = 6;
_L0:
  LogIfFail("Failed to handle ValueIs",iVar1);
  return;
}

