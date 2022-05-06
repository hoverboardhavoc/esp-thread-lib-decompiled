/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ClearSrcMatchExtEntries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ClearSrcMatchExtEntries() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
ClearSrcMatchExtEntries
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  int iVar1;
  
  iVar1 = Set((ulong)this,(char *)0x1305);
  if (iVar1 == 0) {
    *(undefined2 *)(this + 0x7a0) = 0;
  }
  return;
}

