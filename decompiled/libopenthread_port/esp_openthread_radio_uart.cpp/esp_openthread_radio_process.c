/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  
  if (DAT_0001319c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_000131a0);
  if (DAT_0001319c != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  if (DAT_00013490 == 4) {
    DAT_000134a0 = 0xffffffff;
    DAT_00013490 = 2;
    DAT_000134a4 = 0xffffffff;
    puVar3 = (undefined4 *)0x0;
    if (DAT_000133d4 != 0) {
      puVar3 = &DAT_000133d0;
    }
    if (DAT_00013494._1_1_ == '\0') {
      otPlatRadioTxDone(s_radio,DAT_000133f0,puVar3);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00013404);
    }
  }
  else if (((DAT_00013490 == 3) && (uVar2 = otPlatTimeGet(), DAT_000134a4 <= extraout_a1)) &&
          ((DAT_000134a4 != extraout_a1 || (DAT_000134a0 <= uVar2)))) {
    otLogWarnPlat("radio tx timeout");
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::HandleRcpTimeout();
    DAT_0001319c = (undefined4 *)0x12d9a;
    uRam00012d94 = 0x12d9e;
    uRam00012d98 = 0x3fc;
    s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)0x12d94,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_000131a0,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)0x12d94);
    _DAT_000131f0 = 0x10000;
    uRam000133fc = 0xffff0000;
    DAT_00013494._0_2_ = (ushort)DAT_00013494 & 0xf0;
    DAT_000134a4 = 0xffffffff;
    uRam000134ac = 0xffffffff;
    uRam000131f4 = 0;
    uRam000131f8 = 0;
    uRam000131fc = 0;
    uRam00013204 = 0;
    uRam00013208 = 0;
    DAT_000133f0 = 0;
    _DAT_00013400 = 0;
    uRam00013402 = 0;
    DAT_00013490 = 0;
    DAT_00013498 = 0;
    DAT_0001349c = 0;
    DAT_000134a0 = 0xffffffff;
    uRam000134a8 = 0xffffffff;
    uRam000134b0 = 0;
    uRam000134b4 = 0;
    pvVar1 = memset((void *)0x134b8,0x1e,0x10);
    DAT_00013408 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

