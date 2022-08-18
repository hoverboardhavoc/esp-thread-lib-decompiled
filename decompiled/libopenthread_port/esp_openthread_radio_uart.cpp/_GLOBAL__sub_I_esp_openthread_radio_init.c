/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  DAT_0001496c = &DAT_0001456a;
  _DAT_00014564 = 0x1456e;
  uRam00014568 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00014564,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00014970,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00014564);
  _DAT_000149c4 = 0x10000;
  uRam00014bcc = 0xffff0000;
  DAT_00014c64._0_1_ = (byte)DAT_00014c64 & 0xf0;
  uRam000149c8 = 0;
  uRam000149cc = 0;
  DAT_00014d08._1_1_ = DAT_00014d08._1_1_ & 1;
  DAT_00014d1c = 0xffffffff;
  uRam00014d24 = 0xffffffff;
  uRam000149d0 = 0;
  uRam000149d8 = 0;
  uRam000149dc = 0;
  DAT_00014bc0 = 0;
  _DAT_00014bd0 = 0;
  uRam00014bd2 = 0;
  DAT_00014c60 = 0;
  DAT_00014c64._2_2_ = 0;
  DAT_00014cae = 0;
  DAT_00014d00 = 0;
  DAT_00014d08._2_1_ = 0;
  DAT_00014d0c = 0;
  DAT_00014d10 = 0;
  DAT_00014d18 = 0xffffffff;
  uRam00014d20 = 0xffffffff;
  uRam00014d28 = 0;
  uRam00014d2c = 0;
  memset((void *)0x14d30,0x1e,0x10);
  DAT_00014bd8 = 0;
  memset(&DAT_00014d40,0,0x10);
  return;
}

