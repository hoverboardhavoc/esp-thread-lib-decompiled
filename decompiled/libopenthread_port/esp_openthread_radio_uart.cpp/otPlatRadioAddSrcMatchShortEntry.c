/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  if (cRam000131f4 != '\0') {
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

