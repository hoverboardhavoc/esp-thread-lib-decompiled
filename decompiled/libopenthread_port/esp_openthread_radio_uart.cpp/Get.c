/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Get(unsigned long, char const*, ...) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::Get(ulong param_1,char *param_2,...)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  char *in_a2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  int iStack_48;
  int aiStack_44 [3];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = in_a3;
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (*(char *)(param_1 + 0x464) == '\0') {
    *(undefined4 **)(param_1 + 0x470) = &uStack_14;
    RequestWithPropertyFormatV
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)param_1,in_a2,2,(ulong)param_2,(char *)0x0,&uStack_14);
    return;
  }
  uVar1 = __assert_func("/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x5f6,
                        "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::Get(spinel_prop_key_t, const char*, ...) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; spinel_prop_key_t = long unsigned int]"
                        ,"mWaitingTid == 0");
  iVar2 = Get(uVar1,(char *)0x1,&_LC13,aiStack_44,&iStack_48);
  if ((iVar2 == 0) && ((aiStack_44[0] != 4 || (iStack_48 != 3)))) {
    otLogCrit(0xc,_LC3,"Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3,iStack_48);
    uVar3 = otExitCodeToString(3);
    otLogCrit(0xc,_LC3,"%s() at %s:%d: %s","CheckSpinelVersion",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
              uVar3);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

