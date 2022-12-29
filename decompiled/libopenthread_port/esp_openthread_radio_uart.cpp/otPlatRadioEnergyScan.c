/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioEnergyScan(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_00016020 & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    DAT_00016158._1_1_ = DAT_00016158._1_1_ | 0x80;
    uRam00016152 = param_1;
    uRam00016154 = param_2;
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x159b0,(char *)0x31);
    if (((iVar1 == 0) &&
        (iVar1 = ot::Spinel::
                 RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                 ::Set(0x159b0,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x159b0,(char *)0x30), iVar1 == 0)) {
      DAT_00016021 = param_1;
    }
  }
  return iVar1;
}

