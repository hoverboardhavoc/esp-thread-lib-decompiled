/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  _DAT_000131cc = 0x12dca;
  uRam00012dc4 = 0x12dce;
  uRam00012dc8 = 0x3fc;
  _s_radio = 0;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)0x12dc4,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_000131d0,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)0x12dc4);
  _DAT_00013220 = 0x10000;
  uRam0001342c = 0xffff0000;
  DAT_000134c4._0_2_ = (ushort)DAT_000134c4 & 0xf0;
  DAT_000134d4 = 0xffffffff;
  uRam000134dc = 0xffffffff;
  uRam00013224 = 0;
  uRam00013228 = 0;
  uRam0001322c = 0;
  uRam00013234 = 0;
  uRam00013238 = 0;
  DAT_00013420 = 0;
  _DAT_00013430 = 0;
  uRam00013432 = 0;
  DAT_000134c0 = 0;
  DAT_000134c8 = 0;
  DAT_000134cc = 0;
  DAT_000134d0 = 0xffffffff;
  uRam000134d8 = 0xffffffff;
  uRam000134e0 = 0;
  uRam000134e4 = 0;
  memset((void *)0x134e8,0x1e,0x10);
  DAT_00013438 = 0;
  return;
}

