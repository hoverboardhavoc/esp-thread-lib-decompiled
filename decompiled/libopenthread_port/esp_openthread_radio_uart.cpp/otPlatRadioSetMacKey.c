/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetMacKey
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetMacKey
               (uchar param_1,uchar param_2,otMacKeyMaterial *param_3,otMacKeyMaterial *param_4,
               otMacKeyMaterial *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SetMacKey((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio,param_1,param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            SetMacKey((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       *)&s_radio,param_1,param_2,param_3,param_4,param_5);
    uVar2 = 2;
    if (iVar1 != 7) {
      uVar2 = 1;
    }
    uVar2 = otExitCodeToString(uVar2);
    otLogCritPlat("%s() at %s:%d: %s","otPlatRadioSetMacKey",
                  "/home/wangqixiang/workspace/gitlab-esp/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
                  ,0xf8,uVar2);
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            SetMacKey((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       *)&s_radio,param_1,param_2,param_3,param_4,param_5);
    __status = 2;
    if (iVar1 != 7) {
      __status = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
  return;
}

