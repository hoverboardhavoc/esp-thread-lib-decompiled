/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
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
  
  if (DAT_00015d2c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00015d30);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  RecoverFromRcpFailure
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             &s_radio);
  if (DAT_00015d2c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)&s_radio);
  }
  if (DAT_00016020 == 4) {
    DAT_000160d8 = 0xffffffff;
    DAT_00016020 = 2;
    DAT_000160dc = 0xffffffff;
    puVar2 = (undefined4 *)0x0;
    if (DAT_00015f64 != 0) {
      puVar2 = &DAT_00015f60;
    }
    if (DAT_000160c8._2_1_ == '\0') {
      otPlatRadioTxDone(s_radio,DAT_00015f80,puVar2);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00015f94);
    }
  }
  else if (DAT_00016020 == 3) {
    uVar1 = otPlatTimeGet();
    if ((DAT_000160dc <= extraout_a1) && ((DAT_000160dc != extraout_a1 || (DAT_000160d8 <= uVar1))))
    {
      otLogWarnPlat("radio tx timeout");
      DAT_00016100 = DAT_00016100 + 1;
      DAT_000160c8._1_1_ = DAT_000160c8._1_1_ | 0x40;
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

