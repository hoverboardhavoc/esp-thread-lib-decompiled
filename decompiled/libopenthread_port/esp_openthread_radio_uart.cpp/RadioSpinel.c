/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  this[0xc] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              0x0;
  this[0xd] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              0x0;
  *(short *)(this + 8) = ((short)this + 0x40a) - (short)(this + 0xe);
  esp::openthread::UartSpinelInterface::UartSpinelInterface
            ((UartSpinelInterface *)(this + 0x410),HandleReceivedFrame,this,
             (MultiFrameBuffer *)(this + 4));
  *(undefined2 *)(this + 0x460) = 0;
  this[0x462] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x1;
  this[0x463] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  this[0x464] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x468) = 0;
  *(undefined4 *)(this + 0x46c) = 0;
  *(undefined4 *)(this + 0x474) = 0;
  *(undefined4 *)(this + 0x478) = 0;
  *(undefined4 *)(this + 0x660) = 0;
  *(undefined2 *)(this + 0x66c) = 0;
  *(undefined2 *)(this + 0x66e) = 0xffff;
  this[0x670] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  this[0x671] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  this[0x672] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x700) = 0;
  this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x704] & 0xf0);
  this[0x705] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  *(undefined4 *)(this + 0x708) = 0;
  *(undefined4 *)(this + 0x70c) = 0;
  *(undefined4 *)(this + 0x710) = 0xffffffff;
  *(undefined4 *)(this + 0x714) = 0xffffffff;
  *(undefined4 *)(this + 0x718) = 0xffffffff;
  *(undefined4 *)(this + 0x71c) = 0xffffffff;
  *(undefined4 *)(this + 0x720) = 0;
  *(undefined4 *)(this + 0x724) = 0;
  memset(this + 0x728,0x1e,0x10);
  this[0x678] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )0x0;
  return;
}

