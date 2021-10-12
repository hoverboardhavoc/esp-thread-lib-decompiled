/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioDisable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioDisable(void)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = DAT_00013408;
  if (DAT_00013408 != 0) {
    if (DAT_00013408 == 1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d08,(char *)0x20,&_LC36,0);
      if (iVar1 != 0) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d08,(char *)0x20,&_LC36,0);
        uVar2 = 2;
        if (iVar1 != 7) {
          uVar2 = 1;
        }
        uVar2 = otExitCodeToString(uVar2);
        _otLogCrit(0xd,"%s() at %s:%d: %s","Disable",
                   "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x803
                   ,uVar2);
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d08,(char *)0x20,&_LC36,0);
        __status = 2;
        if (iVar1 != 7) {
          __status = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      DAT_00013408 = 0;
      s_radio = 0;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

