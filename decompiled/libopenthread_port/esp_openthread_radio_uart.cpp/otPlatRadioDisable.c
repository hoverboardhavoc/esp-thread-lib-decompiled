/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioDisable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int otPlatRadioDisable(void)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = DAT_000134c0;
  if (DAT_000134c0 != 0) {
    if (DAT_000134c0 == 1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12dc0,(char *)0x20,&_LC36,0);
      if (iVar1 != 0) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12dc0,(char *)0x20,&_LC36,0);
        uVar2 = 2;
        if (iVar1 != 7) {
          uVar2 = 1;
        }
        uVar2 = otExitCodeToString(uVar2);
        _otLogCrit(0xd,"%s() at %s:%d: %s","Disable",
                   "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x804
                   ,uVar2);
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12dc0,(char *)0x20,&_LC36,0);
        __status = 2;
        if (iVar1 != 7) {
          __status = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      DAT_000134c0 = 0;
      _s_radio = 0;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

