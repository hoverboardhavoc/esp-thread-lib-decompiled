/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
  
  poVar3 = aoStack_18;
  poVar4 = param_1 + 7;
  do {
    *poVar3 = *poVar4;
    bVar1 = param_1 != poVar4;
    poVar3 = poVar3 + 1;
    poVar4 = poVar4 + -1;
  } while (bVar1);
  iVar2 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,aoStack_18);
  if (iVar2 == 0) {
    return;
  }
  iVar2 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,aoStack_18);
  uVar5 = 2;
  if (iVar2 != 7) {
    uVar5 = 1;
  }
  uVar5 = otExitCodeToString(uVar5);
  _otLogCrit(0xd,"%s() at %s:%d: %s","otPlatRadioSetExtendedAddress",
             "/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
             ,0x51,uVar5);
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

