/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckSpinelVersion
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::CheckSpinelVersion() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
CheckSpinelVersion(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_18;
  int aiStack_14 [3];
  
  iVar1 = Get((ulong)this,(char *)0x1,&_LC13,aiStack_14,&iStack_18);
  if ((iVar1 == 0) && ((aiStack_14[0] != 4 || (iStack_18 != 3)))) {
    otLogCrit(0xc,_LC3,"Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3,iStack_18);
    uVar2 = otExitCodeToString(3);
    otLogCrit(0xc,_LC3,"%s() at %s:%d: %s","CheckSpinelVersion",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
              uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

