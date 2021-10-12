/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  DAT_00013114 = &DAT_00012d12;
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
  memset(&DAT_00013430,0x1e,0x10);
  DAT_00013380 = 0;
  return;
}

