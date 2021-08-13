/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
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
  
  iVar1 = *(int *)(this + 0x700);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      iVar1 = Set((ulong)this,(char *)0x20,&_LC41,0);
      if (iVar1 != 0) {
        iVar1 = Set((ulong)this,(char *)0x20,&_LC41,0);
        if (iVar1 == 7) {
          uVar2 = 2;
        }
        else {
          uVar2 = 1;
        }
        uVar2 = otExitCodeToString(uVar2);
        otLogCrit(0xc,_LC3,"%s() at %s:%d: %s","Disable",
                  "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x7e8,
                  uVar2);
        iVar1 = Set((ulong)this,(char *)0x20,&_LC41,0);
        if (iVar1 == 7) {
          iVar1 = 2;
        }
        else {
          iVar1 = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(iVar1);
      }
      *(undefined4 *)(this + 0x700) = 0;
      *(undefined4 *)this = 0;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

