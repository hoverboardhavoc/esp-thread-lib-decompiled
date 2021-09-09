/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  
  iVar1 = Get((ulong)this,(char *)0x1,&_LC8,&iStack_18,aiStack_14);
  if (iVar1 == 0) {
    if ((iStack_18 != 4) || (aiStack_14[0] != 3)) {
      otLogCrit(0xc,"-PLAT----: ","Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3);
      uVar2 = otExitCodeToString(3);
      otLogCrit(0xc,"-PLAT----: ","%s() at %s:%d: %s","CheckSpinelVersion",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
                uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return;
}

