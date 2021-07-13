/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetExtendedAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetExtendedAddress(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  otExtAddress aoStack_18 [20];
  
  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
    aoStack_18[uVar3] = *(otExtAddress *)((7 - uVar3) + param_1);
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)s_radio,aoStack_18);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)s_radio,aoStack_18);
  if (iVar1 == 7) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","otPlatRadioSetExtendedAddress",
            "/home/chenshu/code/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
            ,0x4a,uVar2);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetExtendedAddress((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)s_radio,aoStack_18);
  if (iVar1 == 7) {
    iVar1 = 2;
  }
  else {
    iVar1 = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}

