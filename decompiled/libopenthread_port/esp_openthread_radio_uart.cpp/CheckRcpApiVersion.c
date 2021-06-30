/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckRcpApiVersion
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   CheckRcpApiVersion(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, bool aSupportsRcpApiVersion) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
CheckRcpApiVersion(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this,bool aSupportsRcpApiVersion)

{
  otError oVar1;
  undefined4 uVar2;
  undefined3 in_register_0000202d;
  int local_14;
  uint rcpApiVersion;
  
  local_14 = 1;
  if (CONCAT31(in_register_0000202d,aSupportsRcpApiVersion) == 0) {
    oVar1 = OT_ERROR_NONE;
  }
  else {
    oVar1 = Get(this,0xb0,"i",&local_14);
    if (oVar1 != OT_ERROR_NONE) {
      return oVar1;
    }
  }
  otLogNote(0xc,_LC2,"RCP API Version: %u",local_14);
  if (local_14 - 1U < 3) {
    return oVar1;
  }
  otLogCrit(0xc,_LC2,"RCP API Version %u is not in the supported range [%u-%u]",1,3);
  uVar2 = otExitCodeToString(3);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","CheckRcpApiVersion",
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x19e,uVar2)
  ;
                    /* WARNING: Subroutine does not return */
  exit(3);
}

