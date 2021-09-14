/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  
  if (DAT_000130cc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  esp::openthread::UartSpinelInterface::Process((esp_openthread_mainloop_context_t *)&DAT_000130d0);
  if (DAT_000130cc != &s_radio) {
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio);
  }
  if (DAT_000133c0 == 4) {
    DAT_000133d0 = 0xffffffff;
    DAT_000133c0 = 2;
    DAT_000133d4 = 0xffffffff;
    puVar3 = (undefined4 *)0x0;
    if (DAT_00013304 != 0) {
      puVar3 = &DAT_00013300;
    }
    if (DAT_000133c4._1_1_ == '\0') {
      otPlatRadioTxDone(_s_radio,DAT_00013320,puVar3);
    }
    else {
      otPlatDiagRadioTransmitDone(DAT_00013334);
    }
  }
  else if (((DAT_000133c0 == 3) && (uVar2 = otPlatTimeGet(), DAT_000133d4 <= extraout_a1)) &&
          ((DAT_000133d4 != extraout_a1 || (DAT_000133d0 <= uVar2)))) {
    _otLogWarn(0xc,"radio tx timeout");
    ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::HandleRcpTimeout();
    DAT_000130cc = (undefined1 *)0x12cca;
    uRam00012cc4 = 0x12cce;
    uRam00012cc8 = 0x3fc;
    _s_radio = 0;
    ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
              ((MultiFrameBuffer<(unsigned_short)1024> *)0x12cc4,0);
    esp::openthread::UartSpinelInterface::UartSpinelInterface
              ((UartSpinelInterface *)&DAT_000130d0,
               ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)0x12cc4);
    _DAT_00013120 = 0x10000;
    uRam0001332c = 0xffff0000;
    DAT_000133c4._0_2_ = (ushort)DAT_000133c4 & 0xf0;
    DAT_000133d4 = 0xffffffff;
    uRam000133dc = 0xffffffff;
    uRam00013124 = 0;
    uRam00013128 = 0;
    uRam0001312c = 0;
    uRam00013134 = 0;
    uRam00013138 = 0;
    DAT_00013320 = 0;
    _DAT_00013330 = 0;
    uRam00013332 = 0;
    DAT_000133c0 = 0;
    DAT_000133c8 = 0;
    DAT_000133cc = 0;
    DAT_000133d0 = 0xffffffff;
    uRam000133d8 = 0xffffffff;
    uRam000133e0 = 0;
    uRam000133e4 = 0;
    pvVar1 = memset((void *)0x133e8,0x1e,0x10);
    DAT_00013338 = 0;
    return pvVar1;
  }
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio);
  return (void *)0x0;
}

