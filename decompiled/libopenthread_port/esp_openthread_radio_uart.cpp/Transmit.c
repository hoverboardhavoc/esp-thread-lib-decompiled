/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Transmit(otRadioFrame&) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Transmit(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
        otRadioFrame *param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  
  if (*(int *)(this + 0x700) != 2) {
    if (*(int *)(this + 0x700) != 1) {
      return 0xd;
    }
    if (((byte)this[0x670] & 0x10) == 0) {
      return 0xd;
    }
  }
  *(otRadioFrame **)(this + 0x660) = param_1;
  otPlatRadioTxStarted(*(undefined4 *)this);
  iVar1 = Request((ulong)this,3,(char *)0x71);
  if (iVar1 == 0) {
    *(undefined4 *)(this + 0x700) = 3;
    uVar2 = otPlatTimeGet();
    *(uint *)(this + 0x710) = uVar2 + 5000000;
    *(uint *)(this + 0x714) = (uint)(uVar2 + 5000000 < uVar2) + extraout_a1;
  }
  return iVar1;
}

