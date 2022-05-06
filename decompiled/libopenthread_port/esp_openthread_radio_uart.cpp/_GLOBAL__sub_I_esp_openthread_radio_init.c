/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  DAT_000140d4 = &DAT_00013cd2;
  _DAT_00013ccc = 0x13cd6;
  uRam00013cd0 = 0x3fc;
  s_radio = 0;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00013ccc,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_000140d8,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00013ccc);
  _DAT_0001412c = 0x10000;
  uRam00014334 = 0xffff0000;
  DAT_000143cc._0_1_ = (byte)DAT_000143cc & 0xf0;
  uRam00014130 = 0;
  uRam00014134 = 0;
  DAT_00014470._1_1_ = DAT_00014470._1_1_ & 1;
  DAT_00014484 = 0xffffffff;
  uRam0001448c = 0xffffffff;
  uRam00014138 = 0;
  uRam00014140 = 0;
  uRam00014144 = 0;
  DAT_00014328 = 0;
  _DAT_00014338 = 0;
  uRam0001433a = 0;
  DAT_000143c8 = 0;
  DAT_000143cc._2_2_ = 0;
  DAT_00014416 = 0;
  DAT_00014468 = 0;
  DAT_00014470._2_1_ = 0;
  DAT_00014474 = 0;
  DAT_00014478 = 0;
  DAT_00014480 = 0xffffffff;
  uRam00014488 = 0xffffffff;
  uRam00014490 = 0;
  uRam00014494 = 0;
  memset((void *)0x14498,0x1e,0x10);
  DAT_00014340 = 0;
  return;
}

