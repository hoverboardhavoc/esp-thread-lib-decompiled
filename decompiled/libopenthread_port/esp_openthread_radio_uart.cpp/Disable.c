/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
                      0x819,uVar2);
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

