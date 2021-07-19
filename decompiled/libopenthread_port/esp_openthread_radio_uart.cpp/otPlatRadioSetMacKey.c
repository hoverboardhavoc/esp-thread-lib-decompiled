/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetMacKey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetMacKey(uchar param_1,otMacKey *param_2,otMacKey *param_3,otMacKey *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetMacKey('0',param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetMacKey('0',param_1,param_2,param_3,param_4);
  if (iVar1 == 7) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","otPlatRadioSetMacKey",
            "/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
            ,0xe9,uVar2);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetMacKey('0',param_1,param_2,param_3,param_4);
  if (iVar1 == 7) {
    iVar1 = 2;
  }
  else {
    iVar1 = 1;
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar1);
}

