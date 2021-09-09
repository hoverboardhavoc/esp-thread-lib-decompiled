/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RadioSpinel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RadioSpinel() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RadioSpinel(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
            *this)

{
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 0x40c) = this + 10;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 4) = this + 0xe;
  *(undefined2 *)(this + 8) = 0x3fc;
  *(undefined4 *)this = 0;
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)(this + 4),0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)(this + 0x410),HandleReceivedFrame,this,
             (MultiFrameBuffer *)(this + 4));
  *(undefined4 *)(this + 0x460) = 0x10000;
  *(undefined4 *)(this + 0x66c) = 0xffff0000;
  *(ushort *)(this + 0x704) = *(ushort *)(this + 0x704) & 0xf0;
  *(undefined4 *)(this + 0x714) = 0xffffffff;
  *(undefined4 *)(this + 0x71c) = 0xffffffff;
  this[0x464] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x468) = 0;
  *(undefined4 *)(this + 0x46c) = 0;
  *(undefined4 *)(this + 0x474) = 0;
  *(undefined4 *)(this + 0x478) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined2 *)(this + 0x670) = 0;
  this[0x672] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x700) = 0;
  *(undefined4 *)(this + 0x708) = 0;
  *(undefined4 *)(this + 0x70c) = 0;
  *(undefined4 *)(this + 0x710) = 0xffffffff;
  *(undefined4 *)(this + 0x718) = 0xffffffff;
  *(undefined4 *)(this + 0x720) = 0;
  *(undefined4 *)(this + 0x724) = 0;
  memset(this + 0x728,0x1e,0x10);
  this[0x678] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  return;
}

