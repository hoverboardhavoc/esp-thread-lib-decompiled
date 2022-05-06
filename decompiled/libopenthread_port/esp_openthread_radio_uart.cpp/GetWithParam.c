/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetWithParam
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::GetWithParam(unsigned long, unsigned char const*, unsigned
   int, char const*, ...) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::GetWithParam(ulong param_1,uchar *param_2,uint param_3,char *param_4,...)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  ulong in_a4;
  uint uVar6;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  int iVar7;
  undefined1 auStack_58 [16];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (*(char *)(param_1 + 0x468) == '\0') {
    do {
      RecoverFromRcpFailure
                ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)param_1);
      *(undefined4 **)(param_1 + 0x474) = &uStack_c;
      RequestWithPropertyFormat((char *)param_1,in_a4,2,(char *)param_2);
    } while (*(int *)(param_1 + 0x7a8) << 0x11 < 0);
    return;
  }
  uVar2 = __assert_func(0,0,0,0);
  if ((*(uint *)(uVar2 + 0x704) >> 3 & 1) != 0) {
    uVar4 = otPlatTimeGet();
    if ((extraout_a1_01 < *(uint *)(uVar2 + 0x7c4)) ||
       ((*(uint *)(uVar2 + 0x7c4) == extraout_a1_01 && (uVar4 < *(uint *)(uVar2 + 0x7c0))))) {
      iVar7 = 0;
      goto _L0;
    }
  }
  otLogDebgPlat("Trying to get RCP time offset");
  pcVar3 = (char *)spinel_datatype_pack(auStack_58,8,&_LC19,0,0);
  iVar7 = 3;
  if (pcVar3 + -1 < (char *)0x8) {
    uVar4 = otPlatTimeGet();
    iVar7 = GetWithParam(uVar2,(uchar *)0x802,(uint)auStack_58,pcVar3);
    uVar5 = otPlatTimeGet();
    if (iVar7 == 0) {
      uVar6 = uVar5 >> 1 | extraout_a1_00 << 0x1f;
      uVar4 = (uVar4 >> 1 | extraout_a1 << 0x1f) + uVar6;
      iVar1 = -uVar4;
      *(int *)(uVar2 + 0x7c8) = iVar1;
      *(byte *)(uVar2 + 0x704) = *(byte *)(uVar2 + 0x704) | 8;
      *(uint *)(uVar2 + 0x7cc) =
           -(uint)(iVar1 != 0) -
           ((uint)(uVar4 < uVar6) + (extraout_a1 >> 1) + (extraout_a1_00 >> 1));
      *(uint *)(uVar2 + 0x7c0) = uVar5 + 60000000;
      *(uint *)(uVar2 + 0x7c4) = (uVar5 + 60000000 < uVar5) + extraout_a1_00;
    }
    else {
      *(uint *)(uVar2 + 0x7c0) = uVar5;
      *(uint *)(uVar2 + 0x7c4) = extraout_a1_00;
    }
  }
_L0:
  LogIfFail("Error calculating RCP time offset: %s",iVar7);
  return;
}

