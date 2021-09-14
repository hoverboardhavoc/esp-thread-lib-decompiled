/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  int aiStack_14 [4];
  
  iVar1 = Get((ulong)this,(char *)0x1,&_LC7,&iStack_18,aiStack_14);
  if (iVar1 == 0) {
    if ((iStack_18 != 4) || (aiStack_14[0] != 3)) {
      _otLogCrit(0xc,"Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3);
      uVar2 = otExitCodeToString(3);
      _otLogCrit(0xc,"%s() at %s:%d: %s","CheckSpinelVersion",
                 "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
                 uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return;
}

