/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  
  if (DAT_00013184 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_00013188);
  if (DAT_00013184 != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  if (DAT_00013478 == 4) {
    DAT_00013488 = 0xffffffff;
    DAT_00013478 = 2;
    DAT_0001348c = 0xffffffff;
    puVar3 = (undefined4 *)0x0;
    if (DAT_000133bc != 0) {
      puVar3 = &DAT_000133b8;
    }
    if (DAT_0001347c._1_1_ == '\0') {
      otPlatRadioTxDone(s_radio,DAT_000133d8,puVar3);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_000133ec);
    }
  }
  else if (((DAT_00013478 == 3) && (uVar2 = otPlatTimeGet(), DAT_0001348c <= extraout_a1)) &&
          ((DAT_0001348c != extraout_a1 || (DAT_00013488 <= uVar2)))) {
    otLogWarnPlat("radio tx timeout");
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::HandleRcpTimeout();
    DAT_00013184 = (undefined4 *)&DAT_00012d82;
    DAT_00012d7c = &DAT_00012d86;
    DAT_00012d80 = 0x3fc;
    s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012d7c,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_00013188,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012d7c);
    _DAT_000131d8 = 0x10000;
    DAT_000133e4 = 0xffff0000;
    DAT_0001347c._0_2_ = (ushort)DAT_0001347c & 0xf0;
    DAT_0001348c = 0xffffffff;
    DAT_00013494 = 0xffffffff;
    DAT_000131dc = 0;
    DAT_000131e0 = 0;
    DAT_000131e4 = 0;
    DAT_000131ec = 0;
    DAT_000131f0 = 0;
    DAT_000133d8 = 0;
    _DAT_000133e8 = 0;
    DAT_000133ea = 0;
    DAT_00013478 = 0;
    DAT_00013480 = 0;
    DAT_00013484 = 0;
    DAT_00013488 = 0xffffffff;
    DAT_00013490 = 0xffffffff;
    DAT_00013498 = 0;
    DAT_0001349c = 0;
    pvVar1 = memset(&DAT_000134a0,0x1e,0x10);
    DAT_000133f0 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

