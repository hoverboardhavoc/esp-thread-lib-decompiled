/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagChannelSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagChannelSet(void)

{
  char acStack_110 [264];
  
  snprintf(acStack_110,0x100,"channel %d");
  DAT_00014474 = 0;
  DAT_00014478 = 0;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x13cc8,(char *)0x3bc0);
  DAT_00014474 = 0;
  DAT_00014478 = 0;
  return;
}

