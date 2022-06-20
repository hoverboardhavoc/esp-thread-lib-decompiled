/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_radio_process(void)

{
  uint uVar1;
  uint extraout_a1;
  undefined4 *puVar2;
  
  if (DAT_00014894 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00014898);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RecoverFromRcpFailure
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             &s_radio);
  if (DAT_00014894 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  if (DAT_00014b88 == 4) {
    DAT_00014c40 = 0xffffffff;
    DAT_00014b88 = 2;
    DAT_00014c44 = 0xffffffff;
    puVar2 = (undefined4 *)0x0;
    if (DAT_00014acc != 0) {
      puVar2 = &DAT_00014ac8;
    }
    if (DAT_00014c30._2_1_ == '\0') {
      otPlatRadioTxDone(s_radio,DAT_00014ae8,puVar2);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00014afc);
    }
  }
  else if (DAT_00014b88 == 3) {
    uVar1 = otPlatTimeGet();
    if ((DAT_00014c44 <= extraout_a1) && ((DAT_00014c44 != extraout_a1 || (DAT_00014c40 <= uVar1))))
    {
      otLogWarnPlat("radio tx timeout");
      DAT_00014c30._1_1_ = DAT_00014c30._1_1_ | 0x40;
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

