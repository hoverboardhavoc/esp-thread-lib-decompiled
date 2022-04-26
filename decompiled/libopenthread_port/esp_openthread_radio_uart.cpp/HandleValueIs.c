/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  undefined4 ****ppppuVar3;
  undefined2 in_register_00002036;
  uint uVar4;
  int local_c0;
  uint uStack_bc;
  undefined4 ***apppuStack_b8 [41];
  
  iVar1 = CONCAT22(in_register_00002036,param_3);
  if (param_1 == 0x71) {
    iVar1 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x600),param_2,param_3,&local_c0);
    if (iVar1 != 0) goto _L0;
    if (((*(uint *)(this + 0x704) & 1) != 0) || (1 < *(uint *)(this + 0x700))) {
      if ((char)s_radio == '\0') {
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
    apppuStack_b8[0] = (undefined4 ****)0x0;
    local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC11,apppuStack_b8);
    if (0 < local_c0) {
      iVar1 = 0;
      if (apppuStack_b8[0] + -0x1c < (undefined4 ****)0x11) {
        if (*(int *)(this + 0x700) != 0) {
          uVar2 = spinel_status_to_cstr();
          otLogCritPlat("Unexpected RCP reset: %s",uVar2);
          uVar2 = otExitCodeToString(4);
          otLogCritPlat("%s() at %s:%d: %s","HandleRcpUnexpectedReset",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x8b2,uVar2);
                    /* WARNING: Subroutine does not return */
          exit(4);
        }
        uVar2 = spinel_status_to_cstr();
        otLogInfoPlat("RCP reset: %s",uVar2);
        this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       )((byte)this[0x704] | 2);
      }
      else {
        uVar2 = spinel_status_to_cstr();
        otLogInfoPlat("RCP last status: %s",uVar2);
      }
      goto _L0;
    }
_L0:
    iVar1 = 6;
  }
  else {
    if (param_1 == 0x39) {
      local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC61,&uStack_bc,apppuStack_b8);
      if (local_c0 < 1) goto _L0;
      otPlatRadioEnergyScanDone(*(undefined4 *)this,(int)(char)apppuStack_b8[0]);
    }
    else if (param_1 == 0x70) {
      uStack_bc = 0x97;
      iVar1 = spinel_datatype_unpack_in_place(param_2,iVar1,&_LC10,apppuStack_b8,&uStack_bc);
      uVar4 = uStack_bc;
      local_c0 = iVar1;
      if (0x96 < uStack_bc) {
        iVar1 = __assert_func(0,0,0,0);
      }
      if (iVar1 < 1) goto _L0;
      *(undefined1 *)((int)apppuStack_b8 + uVar4) = 0;
      ppppuVar3 = apppuStack_b8;
_L0:
      otLogDebgPlat("RCP => %s",ppppuVar3);
    }
    else if ((param_1 == 0x74) && ((*(uint *)(this + 0x704) >> 2 & 1) != 0)) {
      local_c0 = spinel_datatype_unpack(param_2,iVar1,&_LC24,apppuStack_b8);
      if (-1 < local_c0) {
        local_c0 = spinel_datatype_unpack
                             (param_2 + local_c0,iVar1 - local_c0 & 0xffff,&_LC35,&uStack_bc);
        if (0 < local_c0) {
          uVar4 = uStack_bc & 0xff;
          if (uVar4 < 5) {
            if (uVar4 < 3) {
              otLogCritPlat("RCP => %s");
            }
            else {
              otLogWarnPlat("RCP => %s");
            }
          }
          else if (uVar4 == 5) {
            otLogNotePlat("RCP => %s",apppuStack_b8[0]);
          }
          else {
            ppppuVar3 = (undefined4 ****)apppuStack_b8[0];
            if (uVar4 != 6) goto _L0;
            otLogInfoPlat("RCP => %s");
          }
          goto _L0;
        }
      }
      goto _L0;
    }
_L0:
    iVar1 = 0;
  }
_L0:
  LogIfFail("Failed to handle ValueIs",iVar1);
  return;
}

