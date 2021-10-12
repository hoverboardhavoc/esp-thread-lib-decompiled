/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * esp_openthread_radio_process(void)

{
  void *pvVar1;
  uint uVar2;
  uint extraout_a1;
  undefined4 *puVar3;
  
  if (DAT_00013114 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00013118);
  if (DAT_00013114 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  if (DAT_00013408 == 4) {
    DAT_00013418 = 0xffffffff;
    DAT_00013408 = 2;
    DAT_0001341c = 0xffffffff;
    puVar3 = (undefined4 *)0x0;
    if (DAT_0001334c != 0) {
      puVar3 = &DAT_00013348;
    }
    if (DAT_0001340c._1_1_ == '\0') {
      otPlatRadioTxDone(s_radio,DAT_00013368,puVar3);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_0001337c);
    }
  }
  else if (((DAT_00013408 == 3) && (uVar2 = otPlatTimeGet(), DAT_0001341c <= extraout_a1)) &&
          ((DAT_0001341c != extraout_a1 || (DAT_00013418 <= uVar2)))) {
    _otLogWarn(0xd,"radio tx timeout");
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::HandleRcpTimeout();
    DAT_00013114 = (undefined4 *)&DAT_00012d12;
    DAT_00012d0c = &DAT_00012d16;
    DAT_00012d10 = 0x3fc;
    s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012d0c,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_00013118,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012d0c);
    DAT_00013168 = 0x10000;
    DAT_00013374 = 0xffff0000;
    DAT_0001340c._0_2_ = (ushort)DAT_0001340c & 0xf0;
    DAT_0001341c = 0xffffffff;
    DAT_00013424 = 0xffffffff;
    DAT_0001316c = 0;
    DAT_00013170 = 0;
    DAT_00013174 = 0;
    DAT_0001317c = 0;
    DAT_00013180 = 0;
    DAT_00013368 = 0;
    DAT_00013378 = 0;
    DAT_0001337a = 0;
    DAT_00013408 = 0;
    DAT_00013410 = 0;
    DAT_00013414 = 0;
    DAT_00013418 = 0xffffffff;
    DAT_00013420 = 0xffffffff;
    DAT_00013428 = 0;
    DAT_0001342c = 0;
    pvVar1 = memset(&DAT_00013430,0x1e,0x10);
    DAT_00013380 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

