/*
 * Last changed at upstream commit d5196d896db7230669366a6468859aacccc0f68a
 * https://github.com/espressif/esp-thread-lib/commit/d5196d896db7230669366a6468859aacccc0f68a
 * Upstream date: 2021-12-24 17:07:02 +0800
 * Upstream subject: br: support new mdns interface
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * esp_openthread_radio_process(void)

{
  void *pvVar1;
  uint uVar2;
  uint extraout_a1;
  undefined4 *puVar3;
  
  if (DAT_000131cc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_000131d0);
  if (DAT_000131cc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  if (DAT_000134c0 == 4) {
    DAT_000134d0 = 0xffffffff;
    DAT_000134c0 = 2;
    DAT_000134d4 = 0xffffffff;
    puVar3 = (undefined4 *)0x0;
    if (_DAT_00013404 != 0) {
      puVar3 = &DAT_00013400;
    }
    if (DAT_000134c4._1_1_ == '\0') {
      otPlatRadioTxDone(_s_radio,DAT_00013420,puVar3);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00013434);
    }
  }
  else if (((DAT_000134c0 == 3) && (uVar2 = otPlatTimeGet(), DAT_000134d4 <= extraout_a1)) &&
          ((DAT_000134d4 != extraout_a1 || (DAT_000134d0 <= uVar2)))) {
    _otLogWarn(0xd,"radio tx timeout");
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::HandleRcpTimeout();
    DAT_000131cc = &DAT_00012dca;
    DAT_00012dc4 = &DAT_00012dce;
    DAT_00012dc8 = 0x3fc;
    _s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012dc4,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_000131d0,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012dc4);
    _DAT_00013220 = 0x10000;
    DAT_0001342c = 0xffff0000;
    DAT_000134c4._0_2_ = (ushort)DAT_000134c4 & 0xf0;
    DAT_000134d4 = 0xffffffff;
    DAT_000134dc = 0xffffffff;
    DAT_00013224 = 0;
    DAT_00013228 = 0;
    DAT_0001322c = 0;
    DAT_00013234 = 0;
    DAT_00013238 = 0;
    DAT_00013420 = 0;
    _DAT_00013430 = 0;
    DAT_00013432 = 0;
    DAT_000134c0 = 0;
    DAT_000134c8 = 0;
    DAT_000134cc = 0;
    DAT_000134d0 = 0xffffffff;
    DAT_000134d8 = 0xffffffff;
    DAT_000134e0 = 0;
    DAT_000134e4 = 0;
    pvVar1 = memset(&DAT_000134e8,0x1e,0x10);
    DAT_00013438 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

