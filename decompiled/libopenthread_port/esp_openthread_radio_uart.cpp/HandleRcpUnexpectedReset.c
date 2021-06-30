/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleRcpUnexpectedReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleRcpUnexpectedReset(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, spinel_status_t aStatus) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleRcpUnexpectedReset
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this,spinel_status_t aStatus)

{
  undefined4 uVar1;
  
  uVar1 = spinel_status_to_cstr(aStatus);
  otLogCrit(0xc,_LC2,"Unexpected RCP reset: %s",uVar1);
  uVar1 = otExitCodeToString(4);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","HandleRcpUnexpectedReset",
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x884,uVar1)
  ;
                    /* WARNING: Subroutine does not return */
  exit(4);
}

