/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioEnergyScan(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_00014af8 & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    DAT_00014c30._1_1_ = DAT_00014c30._1_1_ | 0x80;
    uRam00014c2a = param_1;
    uRam00014c2c = param_2;
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x14488,(char *)0x31);
    if (((iVar1 == 0) &&
        (iVar1 = ot::Spinel::
                 RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                 ::Set(0x14488,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14488,(char *)0x30), iVar1 == 0)) {
      DAT_00014af9 = param_1;
    }
  }
  return iVar1;
}

