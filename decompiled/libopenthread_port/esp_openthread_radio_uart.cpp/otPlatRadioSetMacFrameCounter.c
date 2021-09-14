/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetMacFrameCounter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioSetMacFrameCounter(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x12cc0,(char *)0x801,&_LC44,param_1);
  if (iVar1 != 0) {
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x12cc0,(char *)0x801,&_LC44,param_1);
    uVar2 = 2;
    if (iVar1 != 7) {
      uVar2 = 1;
    }
    uVar2 = otExitCodeToString(uVar2);
    _otLogCrit(0xc,"%s() at %s:%d: %s","otPlatRadioSetMacFrameCounter",
               "/home/wangqixiang/workspace/gitlab-esp/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
               ,0xf2,uVar2);
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x12cc0,(char *)0x801,&_LC44,param_1);
    __status = 2;
    if (iVar1 != 7) {
      __status = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
  return;
}

