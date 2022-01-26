/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioAddSrcMatchShortEntry
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this;
  ulong extraout_a1;
  ulong uVar1;
  char *pcVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcVar2 = "S";
  uVar1 = 0x1304;
  this = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
         &s_radio;
  uStack_14 = param_1;
  uStack_10 = param_2;
  uStack_c = param_3;
  uStack_8 = param_4;
  uStack_4 = param_5;
  if (cRam00013224 != '\0') {
    pcVar2 = (char *)0x0;
    this = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           __assert_func(0,0,0,0);
    uVar1 = extraout_a1;
  }
  *(undefined4 **)(this + 0x470) = &uStack_14;
  *(undefined4 *)(this + 0x474) = 7;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RequestV(this,4,uVar1,pcVar2,&uStack_14);
  *(undefined4 *)(this + 0x474) = 0;
  return;
}

