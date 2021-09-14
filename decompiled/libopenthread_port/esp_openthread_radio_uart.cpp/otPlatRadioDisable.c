/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  
  iVar1 = DAT_000133c0;
  if (DAT_000133c0 != 0) {
    if (DAT_000133c0 == 1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12cc0,(char *)0x20,&_LC34,0);
      if (iVar1 != 0) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12cc0,(char *)0x20,&_LC34,0);
        uVar2 = 2;
        if (iVar1 != 7) {
          uVar2 = 1;
        }
        uVar2 = otExitCodeToString(uVar2);
        _otLogCrit(0xc,"%s() at %s:%d: %s","Disable",
                   "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x7f6
                   ,uVar2);
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12cc0,(char *)0x20,&_LC34,0);
        __status = 2;
        if (iVar1 != 7) {
          __status = 1;
        }
                    /* WARNING: Subroutine does not return */
        exit(__status);
      }
      DAT_000133c0 = 0;
      _s_radio = 0;
      iVar1 = 0;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

