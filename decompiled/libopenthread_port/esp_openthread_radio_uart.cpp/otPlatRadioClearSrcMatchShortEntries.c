/*
 * Last changed at upstream commit 9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * https://github.com/espressif/esp-thread-lib/commit/9fabccb43c2318d45d7d893902a614d94d0f2e2a
 * Upstream date: 2022-07-21 09:58:37 +0200
 * Upstream subject: ot_port: Update libs per esp_netif/lwip deps (1937df32)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchShortEntries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchShortEntries(void)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          ClearSrcMatchShortEntries
                    ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                      *)&s_radio);
  if (iVar1 != 0) {
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            ClearSrcMatchShortEntries
                      ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)&s_radio);
    uVar2 = 2;
    if (iVar1 != 7) {
      uVar2 = 1;
    }
    uVar2 = otExitCodeToString(uVar2);
    otLogCritPlat("%s() at %s:%d: %s","otPlatRadioClearSrcMatchShortEntries",
                  "/home/david/repos/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
                  ,0xc2,uVar2);
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
            ClearSrcMatchShortEntries
                      ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)&s_radio);
    __status = 2;
    if (iVar1 != 7) {
      __status = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
  return;
}

