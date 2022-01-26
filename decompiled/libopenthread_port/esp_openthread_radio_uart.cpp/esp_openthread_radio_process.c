/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
  
  if (_DAT_000131cc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_000131d0);
  if (_DAT_000131cc != &s_radio) {
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
    _DAT_000131cc = (undefined1 *)0x12dca;
    uRam00012dc4 = 0x12dce;
    uRam00012dc8 = 0x3fc;
    _s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)0x12dc4,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_000131d0,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)0x12dc4);
    _DAT_00013220 = 0x10000;
    uRam0001342c = 0xffff0000;
    DAT_000134c4._0_2_ = (ushort)DAT_000134c4 & 0xf0;
    DAT_000134d4 = 0xffffffff;
    uRam000134dc = 0xffffffff;
    uRam00013224 = 0;
    uRam00013228 = 0;
    uRam0001322c = 0;
    uRam00013234 = 0;
    uRam00013238 = 0;
    DAT_00013420 = 0;
    _DAT_00013430 = 0;
    uRam00013432 = 0;
    DAT_000134c0 = 0;
    DAT_000134c8 = 0;
    DAT_000134cc = 0;
    DAT_000134d0 = 0xffffffff;
    uRam000134d8 = 0xffffffff;
    uRam000134e0 = 0;
    uRam000134e4 = 0;
    pvVar1 = memset((void *)0x134e8,0x1e,0x10);
    DAT_00013438 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

