/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetNextTid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::GetNextTid() */

uint __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
GetNextTid(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  uint uVar2;
  
  uVar2 = (uint)(byte)this[0x462];
  if (((int)(uint)*(ushort *)(this + 0x460) >> (uVar2 & 0x1f) & 1U) == 0) {
    if (uVar2 < 0xf) {
      RVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              ((char)this[0x462] + 1);
    }
    else {
      RVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              0x1;
    }
    this[0x462] = RVar1;
    *(ushort *)(this + 0x460) = *(ushort *)(this + 0x460) | (ushort)(1 << (uVar2 & 0x1f));
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

