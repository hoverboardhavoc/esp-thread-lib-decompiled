/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioEnergyScan(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = 0x1b;
  if (((((DAT_00013400 & 2) != 0) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d90,(char *)0x31), iVar1 == 0)) &&
      (iVar1 = ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               Set(0x12d90,(char *)0x32), iVar1 == 0)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d90,(char *)0x30), iVar1 == 0)) {
    DAT_00013401 = param_1;
  }
  return iVar1;
}

