/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x8b2,
                uVar1);
                    /* WARNING: Subroutine does not return */
  exit(6);
}

