/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
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
  DAT_0001489c = &DAT_0001449a;
  _DAT_00014494 = 0x1449e;
  uRam00014498 = 0x3fc;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00014494,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_000148a0,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00014494);
  _DAT_000148f4 = 0x10000;
  uRam00014afc = 0xffff0000;
  DAT_00014b94._0_1_ = (byte)DAT_00014b94 & 0xf0;
  uRam000148f8 = 0;
  uRam000148fc = 0;
  DAT_00014c38._1_1_ = DAT_00014c38._1_1_ & 1;
  DAT_00014c4c = 0xffffffff;
  uRam00014c54 = 0xffffffff;
  uRam00014900 = 0;
  uRam00014908 = 0;
  uRam0001490c = 0;
  DAT_00014af0 = 0;
  _DAT_00014b00 = 0;
  uRam00014b02 = 0;
  DAT_00014b90 = 0;
  DAT_00014b94._2_2_ = 0;
  DAT_00014bde = 0;
  DAT_00014c30 = 0;
  DAT_00014c38._2_1_ = 0;
  DAT_00014c3c = 0;
  DAT_00014c40 = 0;
  DAT_00014c48 = 0xffffffff;
  uRam00014c50 = 0xffffffff;
  uRam00014c58 = 0;
  uRam00014c5c = 0;
  memset((void *)0x14c60,0x1e,0x10);
  DAT_00014b08 = 0;
  return;
}

