/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
                      (0x14570,(char *)0x25);
    ot::Spinel::LogIfFail("Get transmit power failed",uVar1);
  }
  return uVar1;
}

