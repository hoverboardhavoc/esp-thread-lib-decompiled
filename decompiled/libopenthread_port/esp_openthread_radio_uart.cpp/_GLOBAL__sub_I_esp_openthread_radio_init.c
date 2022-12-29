/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  _s_radio = 0;
  DAT_00015dbc = &DAT_000159ba;
  _DAT_000159b4 = 0x159be;
  uRam000159b8 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_000159b4,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00015dc0,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_000159b4);
  _DAT_00015e14 = 0x10000;
  uRam0001601c = 0xffff0000;
  uRam00015e18 = 0;
  DAT_000160b4._0_1_ = (byte)DAT_000160b4 & 0xf0;
  uRam00015e1c = 0;
  uRam00015e20 = 0;
  DAT_00016158._1_1_ = DAT_00016158._1_1_ & 1;
  uRam00015e28 = 0;
  uRam00015e2c = 0;
  DAT_00016010 = 0;
  _DAT_00016020 = 0;
  uRam00016022 = 0;
  DAT_000160b0 = 0;
  DAT_000160b4._2_2_ = 0;
  DAT_000160fe = 0;
  DAT_00016150 = 0;
  DAT_00016158._2_1_ = 0;
  DAT_0001615c = 0;
  DAT_00016160 = 0;
  DAT_00016168 = 0xffffffff;
  DAT_0001616c = 0xffffffff;
  uRam00016170 = 0xffffffff;
  uRam00016174 = 0xffffffff;
  uRam00016178 = 0xffffffff;
  uRam0001617c = 0xffffffff;
  memset((void *)0x16180,0x1e,0x10);
  DAT_00016028 = 0;
  memset(&DAT_00016190,0,0x10);
  return;
}

