/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioGetTransmitPower
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatRadioGetTransmitPower(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 7;
  if (param_1 != 0) {
    uVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Get
                      (0x12dc0,(char *)0x25);
    ot::Spinel::LogIfFail("Get transmit power failed",uVar1);
  }
  return uVar1;
}

