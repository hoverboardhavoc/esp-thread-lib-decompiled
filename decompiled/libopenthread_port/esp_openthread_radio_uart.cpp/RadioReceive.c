/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RadioReceive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RadioReceive() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
RadioReceive(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
             *this)

{
  int iVar1;
  
  if (((*(uint *)(this + 0x704) & 1) == 0) && (*(uint *)(this + 0x700) < 2)) {
    return;
  }
  iVar1 = otPlatDiagModeGet();
  if (iVar1 == 0) {
    otPlatRadioReceiveDone(*(undefined4 *)this,this + 0x600,0);
  }
  else {
    otPlatDiagRadioReceiveDone(*(undefined4 *)this,this + 0x600,0);
  }
  return;
}

