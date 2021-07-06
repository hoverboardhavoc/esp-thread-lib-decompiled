/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Receive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Receive(unsigned char) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Receive(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
       uchar param_1)

{
  int iVar1;
  undefined3 in_register_0000202d;
  
  if (*(int *)(this + 0x700) == 0) {
    return 0xd;
  }
  if ((uint)(byte)this[0x671] != CONCAT31(in_register_0000202d,param_1)) {
    iVar1 = Set((ulong)this,(char *)0x21);
    if (iVar1 != 0) {
      return iVar1;
    }
    this[0x671] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   )param_1;
  }
  iVar1 = 0;
  if ((*(int *)(this + 0x700) != 1) || (iVar1 = Set((ulong)this,(char *)0x37), iVar1 == 0)) {
    if ((byte)this[0x463] != 0) {
      *(ushort *)(this + 0x460) =
           ~(ushort)(1 << ((byte)this[0x463] & 0x1f)) & *(ushort *)(this + 0x460);
      this[0x463] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
    }
    *(undefined4 *)(this + 0x700) = 2;
  }
  return iVar1;
}

