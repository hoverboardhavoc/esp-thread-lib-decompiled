/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
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
  DAT_00013184 = &DAT_00012d82;
  DAT_00012d7c = &DAT_00012d86;
  DAT_00012d80 = 0x3fc;
  s_radio = 0;
  ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)&DAT_00012d7c,0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)&DAT_00013188,
             ot::Spinel::
             RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
             HandleReceivedFrame,&s_radio,(MultiFrameBuffer *)&DAT_00012d7c);
  _DAT_000131d8 = 0x10000;
  DAT_000133e4 = 0xffff0000;
  DAT_0001347c._0_2_ = (ushort)DAT_0001347c & 0xf0;
  DAT_0001348c = 0xffffffff;
  DAT_00013494 = 0xffffffff;
  DAT_000131dc = 0;
  DAT_000131e0 = 0;
  DAT_000131e4 = 0;
  DAT_000131ec = 0;
  DAT_000131f0 = 0;
  DAT_000133d8 = 0;
  _DAT_000133e8 = 0;
  DAT_000133ea = 0;
  DAT_00013478 = 0;
  DAT_00013480 = 0;
  DAT_00013484 = 0;
  DAT_00013488 = 0xffffffff;
  DAT_00013490 = 0xffffffff;
  DAT_00013498 = 0;
  DAT_0001349c = 0;
  memset(&DAT_000134a0,0x1e,0x10);
  DAT_000133f0 = 0;
  return;
}

