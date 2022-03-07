/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Enable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Enable(otInstance*) */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Enable(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
      otInstance *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(this + 0x700) == 0) {
    *(otInstance **)this = param_1;
    iVar1 = Set((ulong)this,(char *)0x20);
    if ((((iVar1 == 0) && (iVar1 = Set((ulong)this,(char *)0x36), iVar1 == 0)) &&
        (iVar1 = Set((ulong)this,(char *)0x35), iVar1 == 0)) &&
       (iVar1 = Get((ulong)this,(char *)0x27), iVar1 == 0)) {
      *(undefined4 *)(this + 0x700) = 1;
      uVar2 = 0;
    }
    else {
      uVar2 = otThreadErrorToString();
      otLogWarnPlat("RadioSpinel enable: %s",uVar2);
      uVar2 = 1;
    }
    return uVar2;
  }
  return 0;
}

