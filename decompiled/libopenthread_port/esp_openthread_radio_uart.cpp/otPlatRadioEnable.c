/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatRadioEnable(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00014b90 != 0) {
    return 0;
  }
  s_radio = param_1;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x14490,(char *)0x20);
  if ((((iVar1 == 0) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14490,(char *)0x36), iVar1 == 0)) &&
      (iVar1 = ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               Set(0x14490,(char *)0x35), iVar1 == 0)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Get(0x14490,(char *)0x27), iVar1 == 0)) {
    DAT_00014b90 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = otThreadErrorToString();
    otLogWarnPlat("RadioSpinel enable: %s",uVar2);
    uVar2 = 1;
  }
  return uVar2;
}

