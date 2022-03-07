/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  if (((((DAT_000133e8 & 2) != 0) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d78,(char *)0x31), iVar1 == 0)) &&
      (iVar1 = ot::Spinel::
               RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
               Set(0x12d78,(char *)0x32), iVar1 == 0)) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d78,(char *)0x30), iVar1 == 0)) {
    DAT_000133e9 = param_1;
  }
  return iVar1;
}

