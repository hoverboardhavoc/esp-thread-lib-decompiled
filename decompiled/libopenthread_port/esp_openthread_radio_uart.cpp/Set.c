/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Set(unsigned long, char const*, ...) */

int ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::Set(ulong param_1,char *param_2,...)

{
  int iVar1;
  ulong uVar2;
  uint extraout_a1;
  char *in_a2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
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
    iVar1 = RequestWithExpectedCommandV
                      ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)param_1,6,3,(ulong)param_2,in_a2,&uStack_14);
    return iVar1;
  }
  uVar2 = __assert_func("/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x628,
                        "otError ot::Spinel::RadioSpinel<InterfaceType, ProcessContextType>::Set(spinel_prop_key_t, const char*, ...) [with InterfaceType = esp::openthread::UartSpinelInterface; ProcessContextType = esp_openthread_mainloop_context_t; otError = otError; spinel_prop_key_t = long unsigned int]"
                        ,"mWaitingTid == 0");
  if (*(ushort *)(uVar2 + 0x66e) != extraout_a1) {
    iVar1 = Set(uVar2,(char *)0x36);
    if (iVar1 == 0) {
      *(short *)(uVar2 + 0x66e) = (short)extraout_a1;
    }
    return iVar1;
  }
  return 0;
}

