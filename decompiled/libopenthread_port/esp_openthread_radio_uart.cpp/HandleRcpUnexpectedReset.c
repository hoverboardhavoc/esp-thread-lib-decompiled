/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  otLogCrit(0xc,_LC2,"Unexpected RCP reset: %s",uVar1);
  uVar1 = otExitCodeToString(4);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","HandleRcpUnexpectedReset",
            "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x884,uVar1)
  ;
                    /* WARNING: Subroutine does not return */
  exit(4);
}

