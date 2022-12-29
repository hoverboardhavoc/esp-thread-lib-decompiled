/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  
  if (DAT_00015dbc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00015dc0);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RecoverFromRcpFailure
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             &s_radio);
  if (DAT_00015dbc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  if (DAT_000160b0 == 4) {
    DAT_00016168 = 0xffffffff;
    DAT_000160b0 = 2;
    DAT_0001616c = 0xffffffff;
    puVar2 = (undefined4 *)0x0;
    if (DAT_00015ff4 != 0) {
      puVar2 = &DAT_00015ff0;
    }
    if (DAT_00016158._2_1_ == '\0') {
      otPlatRadioTxDone(_s_radio,DAT_00016010,puVar2);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00016024);
    }
  }
  else if (DAT_000160b0 == 3) {
    uVar1 = otPlatTimeGet();
    if ((DAT_0001616c <= extraout_a1) && ((DAT_0001616c != extraout_a1 || (DAT_00016168 <= uVar1))))
    {
      otLogWarnPlat("radio tx timeout");
      DAT_00016190 = DAT_00016190 + 1;
      DAT_00016158._1_1_ = DAT_00016158._1_1_ | 0x40;
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

