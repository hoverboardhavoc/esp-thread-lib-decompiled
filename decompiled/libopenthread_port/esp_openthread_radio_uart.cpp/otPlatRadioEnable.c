/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 otPlatRadioEnable(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00014c60 != 0) {
    return 0;
  }
  _s_radio = param_1;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x14560,(char *)0x20);
  if ((((iVar1 == 0) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14560,(char *)0x36), iVar1 == 0)) &&
      (iVar1 = ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               Set(0x14560,(char *)0x35), iVar1 == 0)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Get(0x14560,(char *)0x27), iVar1 == 0)) {
    DAT_00014c60 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = otThreadErrorToString();
    otLogWarnPlat("RadioSpinel enable: %s",uVar2);
    uVar2 = 1;
  }
  return uVar2;
}

