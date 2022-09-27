/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
  _DAT_0001497c = &DAT_0001457a;
  _DAT_00014574 = 0x1457e;
  uRam00014578 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00014574,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00014980,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00014574);
  _DAT_000149d4 = 0x10000;
  uRam00014bdc = 0xffff0000;
  DAT_00014c74._0_1_ = (byte)DAT_00014c74 & 0xf0;
  uRam000149d8 = 0;
  uRam000149dc = 0;
  DAT_00014d18._1_1_ = DAT_00014d18._1_1_ & 1;
  DAT_00014d2c = 0xffffffff;
  uRam00014d34 = 0xffffffff;
  uRam000149e0 = 0;
  uRam000149e8 = 0;
  uRam000149ec = 0;
  DAT_00014bd0 = 0;
  _DAT_00014be0 = 0;
  uRam00014be2 = 0;
  DAT_00014c70 = 0;
  DAT_00014c74._2_2_ = 0;
  DAT_00014cbe = 0;
  DAT_00014d10 = 0;
  DAT_00014d18._2_1_ = 0;
  DAT_00014d1c = 0;
  DAT_00014d20 = 0;
  DAT_00014d28 = 0xffffffff;
  uRam00014d30 = 0xffffffff;
  uRam00014d38 = 0;
  uRam00014d3c = 0;
  memset((void *)0x14d40,0x1e,0x10);
  DAT_00014be8 = 0;
  memset(&DAT_00014d50,0,0x10);
  return;
}

