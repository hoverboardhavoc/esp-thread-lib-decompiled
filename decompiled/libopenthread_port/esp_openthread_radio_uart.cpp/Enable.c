/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Enable(otInstance*) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Enable(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
      otInstance *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x700) != 0) {
    return 0;
  }
  *(otInstance **)this = param_1;
  iVar1 = Set((ulong)this,(char *)0x20);
  if ((((iVar1 == 0) && (iVar1 = Set((ulong)this,(char *)0x36), iVar1 == 0)) &&
      (iVar1 = Set((ulong)this,(char *)0x35), iVar1 == 0)) &&
     (iVar1 = Get((ulong)this,(char *)0x27), iVar1 == 0)) {
    *(undefined4 *)(this + 0x700) = 1;
  }
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC3,"RadioSpinel enable: %s",uVar2);
    iVar1 = 1;
  }
  return iVar1;
}

