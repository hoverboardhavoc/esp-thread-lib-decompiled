/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleRcpUnexpectedReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleRcpUnexpectedReset(unsigned long) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::HandleRcpUnexpectedReset(ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = spinel_status_to_cstr();
  otLogCrit(0xc,_LC3,"Unexpected RCP reset: %s",uVar1);
  uVar1 = otExitCodeToString(4);
  otLogCrit(0xc,_LC3,"%s() at %s:%d: %s","HandleRcpUnexpectedReset",
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x884,uVar1)
  ;
                    /* WARNING: Subroutine does not return */
  exit(4);
}

