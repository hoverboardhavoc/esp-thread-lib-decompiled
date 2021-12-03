/*
 * Last changed at upstream commit e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * https://github.com/espressif/esp-thread-lib/commit/e527d6b8e8720c9bde49fec26e19cf437458e3b3
 * Upstream date: 2021-12-03 11:59:45 +0800
 * Upstream subject: port: aggressively process pending tasks (eb7a7fb)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchExtEntries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchExtEntries(void)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x12dc0,(char *)0x1305,0);
  if (iVar1 != 0) {
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x12dc0,(char *)0x1305,0);
    uVar2 = 2;
    if (iVar1 != 7) {
      uVar2 = 1;
    }
    uVar2 = otExitCodeToString(uVar2);
    _otLogCrit(0xd,"%s() at %s:%d: %s","otPlatRadioClearSrcMatchExtEntries",
               "/home/zhangwenxu/ieee802154/esp-openthread/components/openthread_port/src/esp_openthread_radio_uart.cpp"
               ,0xbc,uVar2);
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x12dc0,(char *)0x1305,0);
    __status = 2;
    if (iVar1 != 7) {
      __status = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(__status);
  }
  return;
}

