/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  
  if (DAT_000143c8 != 0) {
    return 0;
  }
  s_radio = param_1;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x13cc8,(char *)0x20);
  if ((((iVar1 == 0) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x13cc8,(char *)0x36), iVar1 == 0)) &&
      (iVar1 = ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               Set(0x13cc8,(char *)0x35), iVar1 == 0)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Get(0x13cc8,(char *)0x27), iVar1 == 0)) {
    DAT_000143c8 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = otThreadErrorToString();
    otLogWarnPlat("RadioSpinel enable: %s",uVar2);
    uVar2 = 1;
  }
  return uVar2;
}

