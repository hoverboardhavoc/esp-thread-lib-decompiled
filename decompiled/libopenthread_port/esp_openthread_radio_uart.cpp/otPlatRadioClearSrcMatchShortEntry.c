/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchShortEntry
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
  if (DAT_0001316c != '\0') {
    pcVar2 = (char *)0x0;
    this = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           __assert_func(0,0,0,0);
    uVar1 = extraout_a1;
  }
  *(undefined4 **)(this + 0x470) = &uStack_14;
  *(undefined4 *)(this + 0x474) = 8;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RequestV(this,5,uVar1,pcVar2,&uStack_14);
  *(undefined4 *)(this + 0x474) = 0;
  return;
}

