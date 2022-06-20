/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Disable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Disable() */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
Disable(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = *(int *)(this + 0x700);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = Set((ulong)this,(char *)0x20,&_LC17,0);
      if (iVar1 != 0) {
        iVar1 = Set((ulong)this,(char *)0x20,&_LC17,0);
        uVar2 = 2;
        if (iVar1 != 7) {
          uVar2 = 1;
        }
        uVar2 = otExitCodeToString(uVar2);
        otLogCritPlat("%s() at %s:%d: %s","Disable",
                      "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                      0x80f,uVar2);
        iVar1 = Set((ulong)this,(char *)0x20,&_LC17,0);
        __status = 2;
        if (iVar1 != 7) {
          __status = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      *(undefined4 *)(this + 0x700) = 0;
      *(undefined4 *)this = 0;
      return 0;
    }
    iVar1 = 0xd;
  }
  return iVar1;
}

