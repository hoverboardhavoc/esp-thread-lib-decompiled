/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  DAT_00014894 = &DAT_00014492;
  _DAT_0001448c = 0x14496;
  uRam00014490 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_0001448c,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00014898,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_0001448c);
  _DAT_000148ec = 0x10000;
  uRam00014af4 = 0xffff0000;
  DAT_00014b8c._0_1_ = (byte)DAT_00014b8c & 0xf0;
  uRam000148f0 = 0;
  uRam000148f4 = 0;
  DAT_00014c30._1_1_ = DAT_00014c30._1_1_ & 1;
  DAT_00014c44 = 0xffffffff;
  uRam00014c4c = 0xffffffff;
  uRam000148f8 = 0;
  uRam00014900 = 0;
  uRam00014904 = 0;
  DAT_00014ae8 = 0;
  _DAT_00014af8 = 0;
  uRam00014afa = 0;
  DAT_00014b88 = 0;
  DAT_00014b8c._2_2_ = 0;
  DAT_00014bd6 = 0;
  DAT_00014c28 = 0;
  DAT_00014c30._2_1_ = 0;
  DAT_00014c34 = 0;
  DAT_00014c38 = 0;
  DAT_00014c40 = 0xffffffff;
  uRam00014c48 = 0xffffffff;
  uRam00014c50 = 0;
  uRam00014c54 = 0;
  memset((void *)0x14c58,0x1e,0x10);
  DAT_00014b00 = 0;
  return;
}

