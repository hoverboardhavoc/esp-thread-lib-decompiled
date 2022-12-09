/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
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
  uint uVar4;
  int iStack_b0;
  uint uStack_ac;
  undefined4 ***apppuStack_a8 [38];
  
  if (param_1 == 0x71) {
    iVar1 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x600),param_2,param_3,&iStack_b0);
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
    apppuStack_a8[0] = (undefined4 ****)0x0;
    iStack_b0 = spinel_datatype_unpack(param_2,&_LC31,apppuStack_a8);
    if (0 < iStack_b0) {
      iVar1 = 0;
      if (apppuStack_a8[0] + -0x1c < (undefined4 ****)0x11) {
        if (*(int *)(this + 0x700) == 0) {
          uVar2 = spinel_status_to_cstr();
          otLogInfoPlat("RCP reset: %s",uVar2);
          this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         )((byte)this[0x704] | 2);
        }
        else {
          *(int *)(this + 0x7e4) = *(int *)(this + 0x7e4) + 1;
          uVar2 = spinel_status_to_cstr();
          otLogCritPlat("Unexpected RCP reset: %s",uVar2);
          this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         )((byte)this[0x7a9] | 0x40);
        }
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
      iStack_b0 = spinel_datatype_unpack(param_2,&_LC44,&uStack_ac,apppuStack_a8);
      if (iStack_b0 < 1) goto _L0;
      this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x7a9] & 0x7f);
      otPlatRadioEnergyScanDone(*(undefined4 *)this,(int)(char)apppuStack_a8[0]);
    }
    else if (param_1 == 0x70) {
      uStack_ac = 0x97;
      iVar1 = spinel_datatype_unpack_in_place(param_2,&_LC50,apppuStack_a8,&uStack_ac);
      uVar4 = uStack_ac;
      iStack_b0 = iVar1;
      if (0x96 < uStack_ac) {
        iVar1 = __assert_func(0,0,0,0);
      }
      if (iVar1 < 1) goto _L0;
      *(undefined1 *)((int)apppuStack_a8 + uVar4) = 0;
      ppppuVar3 = apppuStack_a8;
_L0:
      otLogDebgPlat("RCP => %s",ppppuVar3);
    }
    else if ((param_1 == 0x74) && ((*(uint *)(this + 0x704) >> 2 & 1) != 0)) {
      iStack_b0 = spinel_datatype_unpack(param_2,&_LC52,apppuStack_a8);
      if (-1 < iStack_b0) {
        iStack_b0 = spinel_datatype_unpack
                              (param_2 + iStack_b0,(uint)param_3 - iStack_b0 & 0xffff,&_LC37,
                               &uStack_ac);
        if (0 < iStack_b0) {
          uVar4 = uStack_ac & 0xff;
          if (uVar4 == 5) {
            otLogNotePlat("RCP => %s",apppuStack_a8[0]);
          }
          else if (uVar4 < 6) {
            if (uVar4 < 3) {
              otLogCritPlat("RCP => %s");
            }
            else {
              otLogWarnPlat();
            }
          }
          else {
            ppppuVar3 = (undefined4 ****)apppuStack_a8[0];
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
  UpdateParseErrorCount(this,iVar1);
  LogIfFail("Failed to handle ValueIs",iVar1);
  return;
}

