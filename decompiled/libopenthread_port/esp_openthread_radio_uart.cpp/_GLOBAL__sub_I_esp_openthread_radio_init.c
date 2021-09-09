/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> _GLOBAL__sub_I_esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _GLOBAL__sub_I_esp_openthread_radio_init(void)

{
  DAT_000131b4 = &DAT_00012db2;
  DAT_00012dac = &DAT_00012db6;
  DAT_00012db0 = 0x3fc;
  s_radio = 0;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012dac,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_000131b8,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012dac);
  DAT_00013208 = 0x10000;
  DAT_00013414 = 0xffff0000;
  DAT_000134ac._0_2_ = (ushort)DAT_000134ac & 0xf0;
  DAT_000134bc = 0xffffffff;
  DAT_000134c4 = 0xffffffff;
  DAT_0001320c = 0;
  DAT_00013210 = 0;
  DAT_00013214 = 0;
  DAT_0001321c = 0;
  DAT_00013220 = 0;
  DAT_00013408 = 0;
  _DAT_00013418 = 0;
  DAT_0001341a = 0;
  DAT_000134a8 = 0;
  DAT_000134b0 = 0;
  DAT_000134b4 = 0;
  DAT_000134b8 = 0xffffffff;
  DAT_000134c0 = 0xffffffff;
  DAT_000134c8 = 0;
  DAT_000134cc = 0;
  memset(&DAT_000134d0,0x1e,0x10);
  DAT_00013420 = 0;
  return;
}

