/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleRcpTimeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleRcpTimeout() [clone .isra.14] */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::HandleRcpTimeout(void)

{
  undefined4 uVar1;
  
  uVar1 = otExitCodeToString(6);
  _otLogCrit(0xd,"%s() at %s:%d: %s","HandleRcpTimeout",
             "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8a9,uVar1
            );
                    /* WARNING: Subroutine does not return */
  exit(6);
}

