/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  int local_18;
  int local_14 [4];
  
  iVar1 = Get((ulong)this,(char *)0x1,&_LC34,&local_18,local_14);
  if (iVar1 == 0) {
    if ((local_18 != 4) || (local_14[0] != 3)) {
      otLogCritPlat("Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3);
      uVar2 = otExitCodeToString(3);
      otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",300
                    ,uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return;
}

