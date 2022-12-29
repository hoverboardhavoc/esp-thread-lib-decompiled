/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  ulong extraout_a1;
  undefined4 extraout_a1_00;
  uint *puVar2;
  undefined2 in_register_0000203a;
  uint uVar3;
  undefined4 uVar4;
  code *pcVar5;
  Spinel *apSStack_14 [3];
  
  uVar4 = CONCAT22(in_register_0000203a,param_4);
  if (param_2 == 0) {
    iVar1 = spinel_datatype_unpack(&_LC30,apSStack_14);
    if (0 < iVar1) {
      uVar4 = SpinelStatusToOtError(apSStack_14[0],extraout_a1);
_L0:
      *(undefined4 *)(this + 0x47c) = uVar4;
      goto _L0;
    }
_L0:
    uVar4 = 6;
  }
  else {
    if (param_2 == 0x3bc0) {
      *(undefined4 *)(this + 0x47c) = 0;
      if ((*(int *)(this + 0x7ac) == 0) ||
         (iVar1 = spinel_datatype_unpack_in_place(&_LC52,this + 0x7b0), 0 < iVar1)) goto _L0;
      goto _L0;
    }
    if (*(ulong *)(this + 0x46c) == param_2) {
      if (*(char **)(this + 0x470) == (char *)0x0) {
        if (*(ulong *)(this + 0x478) != param_1) goto _L0;
      }
      else {
        puVar2 = *(uint **)(this + 0x474);
        if (**(char **)(this + 0x470) == '.') {
          *(uint **)(this + 0x474) = puVar2 + 2;
          pcVar5 = (code *)*puVar2;
          uVar3 = puVar2[1];
          if (pcVar5 == (code *)0x0) {
            param_3 = (uchar *)__assert_func(0,0,0,0);
            uVar4 = extraout_a1_00;
          }
          if (((uint)pcVar5 & 1) != 0) {
            pcVar5 = *(code **)(pcVar5 + *(int *)(this + uVar3) + -1);
          }
          uVar4 = (*pcVar5)(this + uVar3,param_3,uVar4);
          goto _L0;
        }
        iVar1 = spinel_datatype_vunpack_in_place();
        if (iVar1 < 1) goto _L0;
      }
      *(undefined4 *)(this + 0x47c) = 0;
      goto _L0;
    }
_L0:
    uVar4 = 2;
  }
  *(undefined4 *)(this + 0x47c) = uVar4;
_L0:
  iVar1 = *(int *)(this + 0x47c);
  UpdateParseErrorCount(this);
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 0xe) {
    return;
  }
  uVar4 = otThreadErrorToString(iVar1);
  otLogWarnPlat("%s: %s","Error processing result",uVar4);
  return;
}

