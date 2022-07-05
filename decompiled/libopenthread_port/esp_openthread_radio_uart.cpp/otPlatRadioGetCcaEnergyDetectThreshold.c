/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioGetCcaEnergyDetectThreshold
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatRadioGetCcaEnergyDetectThreshold(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 != 0) {
    uVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Get
                      (0x14488,(char *)0x24);
    ot::Spinel::LogIfFail("Get CCA ED threshold failed",uVar1);
  }
  return uVar1;
}

