/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  DAT_00014834 = &DAT_00014432;
  _DAT_0001442c = 0x14436;
  uRam00014430 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_0001442c,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00014838,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_0001442c);
  _DAT_0001488c = 0x10000;
  uRam00014a94 = 0xffff0000;
  DAT_00014b2c._0_1_ = (byte)DAT_00014b2c & 0xf0;
  uRam00014890 = 0;
  uRam00014894 = 0;
  DAT_00014bd0._1_1_ = DAT_00014bd0._1_1_ & 1;
  DAT_00014be4 = 0xffffffff;
  uRam00014bec = 0xffffffff;
  uRam00014898 = 0;
  uRam000148a0 = 0;
  uRam000148a4 = 0;
  DAT_00014a88 = 0;
  _DAT_00014a98 = 0;
  uRam00014a9a = 0;
  DAT_00014b28 = 0;
  DAT_00014b2c._2_2_ = 0;
  DAT_00014b76 = 0;
  DAT_00014bc8 = 0;
  DAT_00014bd0._2_1_ = 0;
  DAT_00014bd4 = 0;
  DAT_00014bd8 = 0;
  DAT_00014be0 = 0xffffffff;
  uRam00014be8 = 0xffffffff;
  uRam00014bf0 = 0;
  uRam00014bf4 = 0;
  memset((void *)0x14bf8,0x1e,0x10);
  DAT_00014aa0 = 0;
  return;
}

