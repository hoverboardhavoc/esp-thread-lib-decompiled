/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  
  iVar1 = Get((ulong)this,(char *)0x1,&_LC47,&local_18,local_14);
  if (iVar1 == 0) {
    if ((local_18 != 4) || (local_14[0] != 3)) {
      otLogCritPlat("Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3);
      uVar2 = otExitCodeToString(3);
      otLogCritPlat("%s() at %s:%d: %s","CheckSpinelVersion",
                    "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",300
                    ,uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return;
}

