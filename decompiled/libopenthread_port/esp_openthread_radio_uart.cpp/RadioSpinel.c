/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  *(undefined4 *)this = 0;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 0x40c) = this + 10;
  *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
   (this + 4) = this + 0xe;
  *(undefined2 *)(this + 8) = 0x3fc;
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
            ((MultiFrameBuffer<(unsigned_short)1024> *)(this + 4),0);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)(this + 0x410),HandleReceivedFrame,this,
             (MultiFrameBuffer *)(this + 4));
  *(undefined4 *)(this + 0x464) = 0x10000;
  *(undefined4 *)(this + 0x66c) = 0xffff0000;
  this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x704] & 0xf0);
  this[0x468] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x46c) = 0;
  this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x7a9] & 1);
  *(undefined4 *)(this + 0x7bc) = 0xffffffff;
  *(undefined4 *)(this + 0x7c4) = 0xffffffff;
  *(undefined4 *)(this + 0x470) = 0;
  *(undefined4 *)(this + 0x478) = 0;
  *(undefined4 *)(this + 0x47c) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined2 *)(this + 0x670) = 0;
  this[0x672] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x700) = 0;
  *(undefined2 *)(this + 0x706) = 0;
  *(undefined2 *)(this + 0x74e) = 0;
  *(undefined2 *)(this + 0x7a0) = 0;
  this[0x7aa] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x7ac) = 0;
  *(undefined4 *)(this + 0x7b0) = 0;
  *(undefined4 *)(this + 0x7b8) = 0xffffffff;
  *(undefined4 *)(this + 0x7c0) = 0xffffffff;
  *(undefined4 *)(this + 0x7c8) = 0;
  *(undefined4 *)(this + 0x7cc) = 0;
  memset(this + 2000,0x1e,0x10);
  this[0x678] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  memset(this + 0x7e0,0,0x10);
  return;
}

