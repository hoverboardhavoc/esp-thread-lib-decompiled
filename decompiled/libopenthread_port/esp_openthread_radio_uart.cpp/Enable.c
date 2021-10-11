/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
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
      _otLogWarn(0xd,"RadioSpinel enable: %s",uVar2);
      uVar2 = 1;
    }
    return uVar2;
  }
  return 0;
}

