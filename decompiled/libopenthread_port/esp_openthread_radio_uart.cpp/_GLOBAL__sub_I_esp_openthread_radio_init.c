/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  DAT_000130dc = &DAT_00012cda;
  DAT_00012cd4 = &DAT_00012cde;
  DAT_00012cd8 = 0x3fc;
  _s_radio = 0;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012cd4,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_000130e0,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012cd4);
  DAT_00013130 = 0x10000;
  DAT_0001333c = 0xffff0000;
  DAT_000133d4._0_2_ = (ushort)DAT_000133d4 & 0xf0;
  DAT_000133e4 = 0xffffffff;
  DAT_000133ec = 0xffffffff;
  DAT_00013134 = 0;
  DAT_00013138 = 0;
  DAT_0001313c = 0;
  DAT_00013144 = 0;
  DAT_00013148 = 0;
  DAT_00013330 = 0;
  _DAT_00013340 = 0;
  DAT_00013342 = 0;
  DAT_000133d0 = 0;
  DAT_000133d8 = 0;
  DAT_000133dc = 0;
  DAT_000133e0 = 0xffffffff;
  DAT_000133e8 = 0xffffffff;
  DAT_000133f0 = 0;
  DAT_000133f4 = 0;
  memset(&DAT_000133f8,0x1e,0x10);
  DAT_00013348 = 0;
  return;
}

