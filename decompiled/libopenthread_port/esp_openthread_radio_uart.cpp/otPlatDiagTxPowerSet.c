/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagTxPowerSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagTxPowerSet(void)

{
  char acStack_110 [264];
  
  snprintf(acStack_110,0x100,"power %d");
  DAT_00013410 = 0;
  DAT_00013414 = 0;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x12d08,(char *)0x3bc0);
  DAT_00013410 = 0;
  DAT_00013414 = 0;
  return;
}

