/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_openthread_radio_process(void)

{
  uint uVar1;
  uint extraout_a1;
  undefined4 *puVar2;
  
  if (_DAT_0001497c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00014980);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RecoverFromRcpFailure
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             &s_radio);
  if (_DAT_0001497c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  if (DAT_00014c70 == 4) {
    DAT_00014d28 = 0xffffffff;
    DAT_00014c70 = 2;
    DAT_00014d2c = 0xffffffff;
    puVar2 = (undefined4 *)0x0;
    if (_DAT_00014bb4 != 0) {
      puVar2 = &DAT_00014bb0;
    }
    if (DAT_00014d18._2_1_ == '\0') {
      otPlatRadioTxDone(_s_radio,DAT_00014bd0,puVar2);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00014be4);
    }
  }
  else if (DAT_00014c70 == 3) {
    uVar1 = otPlatTimeGet();
    if ((DAT_00014d2c <= extraout_a1) && ((DAT_00014d2c != extraout_a1 || (DAT_00014d28 <= uVar1))))
    {
      otLogWarnPlat("radio tx timeout");
      DAT_00014d50 = DAT_00014d50 + 1;
      DAT_00014d18._1_1_ = DAT_00014d18._1_1_ | 0x40;
    }
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RecoverFromRcpFailure
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             &s_radio);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return 0;
}

