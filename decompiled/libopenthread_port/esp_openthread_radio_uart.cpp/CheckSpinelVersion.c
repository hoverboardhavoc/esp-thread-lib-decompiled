/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckSpinelVersion
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   CheckSpinelVersion(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
CheckSpinelVersion(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this)

{
  otError oVar1;
  undefined4 uVar2;
  int iStack_18;
  uint versionMinor;
  uint versionMajor;
  
  oVar1 = Get(this,1,"ii",&versionMinor,&iStack_18);
  if ((oVar1 == OT_ERROR_NONE) && ((versionMinor != 4 || (iStack_18 != 3)))) {
    otLogCrit(0xc,_LC2,"Spinel version mismatch - Posix:%d.%d, RCP:%d.%d",4,3,iStack_18);
    uVar2 = otExitCodeToString(3);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","CheckSpinelVersion",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x125,
              uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return oVar1;
}

