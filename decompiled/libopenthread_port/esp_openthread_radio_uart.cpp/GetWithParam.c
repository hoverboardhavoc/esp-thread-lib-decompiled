/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
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
  ulong uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  ulong in_a4;
  uint uVar6;
  undefined4 in_a5;
  uint uVar7;
  undefined4 in_a6;
  undefined4 in_a7;
  int iVar8;
  undefined1 auStack_50 [8];
  uint uStack_48;
  int iStack_44;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (*(char *)(param_1 + 0x464) == '\0') {
    *(undefined4 **)(param_1 + 0x470) = &uStack_c;
    RequestWithPropertyFormat((char *)param_1,in_a4,2,(char *)param_2);
    return;
  }
  uVar1 = __assert_func("/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x611,
                        "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::GetWithParam(spinel_prop_key_t, const uint8_t*, spinel_size_t, const char*, ...) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; spinel_prop_key_t = long unsigned int; uint8_t = unsigned char; spinel_size_t = unsigned int]"
                        ,"mWaitingTid == 0");
  uStack_48 = 0;
  iStack_44 = 0;
  if ((*(uint *)(uVar1 + 0x704) >> 3 & 1) != 0) {
    uVar2 = otPlatTimeGet();
    if ((extraout_a1 < *(uint *)(uVar1 + 0x71c)) ||
       ((*(uint *)(uVar1 + 0x71c) == extraout_a1 && (uVar2 < *(uint *)(uVar1 + 0x718))))) {
      iVar8 = 0;
      goto _L0;
    }
  }
  pcVar3 = (char *)spinel_datatype_pack(auStack_50,8,&_LC37,uStack_48,iStack_44);
  if (pcVar3 + -1 < (char *)0x8) {
    uVar2 = otPlatTimeGet();
    iVar8 = GetWithParam(uVar1,(uchar *)0x802,(uint)auStack_50,pcVar3);
    uVar4 = otPlatTimeGet();
    if (iVar8 == 0) {
      uVar6 = uVar4 >> 1 | extraout_a1_01 << 0x1f;
      uVar2 = (uVar2 >> 1 | extraout_a1_00 << 0x1f) + uVar6;
      uVar7 = uStack_48 - uVar2;
      *(uint *)(uVar1 + 0x720) = uVar7;
      *(uint *)(uVar1 + 0x724) =
           (iStack_44 - ((uint)(uVar2 < uVar6) + (extraout_a1_00 >> 1) + (extraout_a1_01 >> 1))) -
           (uint)(uStack_48 < uVar7);
      *(byte *)(uVar1 + 0x704) = *(byte *)(uVar1 + 0x704) | 8;
      *(uint *)(uVar1 + 0x718) = uVar4 + 60000000;
      *(uint *)(uVar1 + 0x71c) = (uVar4 + 60000000 < uVar4) + extraout_a1_01;
    }
    else {
      *(uint *)(uVar1 + 0x718) = uVar4;
      *(uint *)(uVar1 + 0x71c) = extraout_a1_01;
    }
  }
  else {
    iVar8 = 3;
  }
_L0:
  if (iVar8 != 0) {
    uVar5 = otThreadErrorToString(iVar8);
    otLogWarn(0xc,_LC3,"%s: %s","Error calculating RCP time offset: %s",uVar5);
  }
  return;
}

