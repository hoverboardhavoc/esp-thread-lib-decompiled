/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetExtendedAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetExtendedAddress(otExtAddress *param_1)

{
  bool bVar1;
  int iVar2;
  otExtAddress *poVar3;
  otExtAddress *poVar4;
  undefined4 uVar5;
  int __status;
  otExtAddress aoStack_18 [12];
  
  poVar3 = param_1 + 7;
  poVar4 = aoStack_18;
  do {
    *poVar4 = *poVar3;
    bVar1 = param_1 != poVar3;
    poVar3 = poVar3 + -1;
    poVar4 = poVar4 + 1;
  } while (bVar1);
  iVar2 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,aoStack_18);
  if (iVar2 != 0) {
    iVar2 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,aoStack_18);
    uVar5 = 2;
    if (iVar2 != 7) {
      uVar5 = 1;
    }
    uVar5 = otExitCodeToString(uVar5);
    otLogCritPlat("%s() at %s:%d: %s","otPlatRadioSetExtendedAddress",
                  "/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
                  ,0x5c,uVar5);
    iVar2 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,aoStack_18);
    __status = 2;
    if (iVar2 != 7) {
      __status = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
  return;
}

