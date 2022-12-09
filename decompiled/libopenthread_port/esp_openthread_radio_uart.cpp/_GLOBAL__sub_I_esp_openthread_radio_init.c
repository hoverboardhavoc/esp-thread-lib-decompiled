/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  s_radio = 0;
  DAT_00015d2c = &DAT_0001592a;
  _DAT_00015924 = 0x1592e;
  uRam00015928 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00015924,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00015d30,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00015924);
  _DAT_00015d84 = 0x10000;
  uRam00015f8c = 0xffff0000;
  DAT_00016024._0_1_ = (byte)DAT_00016024 & 0xf0;
  uRam00015d88 = 0;
  uRam00015d8c = 0;
  DAT_000160c8._1_1_ = DAT_000160c8._1_1_ & 1;
  DAT_000160dc = 0xffffffff;
  uRam000160e4 = 0xffffffff;
  uRam00015d90 = 0;
  uRam00015d98 = 0;
  uRam00015d9c = 0;
  DAT_00015f80 = 0;
  _DAT_00015f90 = 0;
  uRam00015f92 = 0;
  DAT_00016020 = 0;
  DAT_00016024._2_2_ = 0;
  DAT_0001606e = 0;
  DAT_000160c0 = 0;
  DAT_000160c8._2_1_ = 0;
  DAT_000160cc = 0;
  DAT_000160d0 = 0;
  DAT_000160d8 = 0xffffffff;
  uRam000160e0 = 0xffffffff;
  uRam000160e8 = 0;
  uRam000160ec = 0;
  memset((void *)0x160f0,0x1e,0x10);
  DAT_00015f98 = 0;
  memset(&DAT_00016100,0,0x10);
  return;
}

