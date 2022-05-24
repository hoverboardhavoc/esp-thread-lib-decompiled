/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetTransmitPower
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioSetTransmitPower(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x14428,(char *)0x25);
  if (iVar1 == 0) {
    DAT_00014bd0._1_1_ = DAT_00014bd0._1_1_ | 8;
    DAT_00014bcf = param_1;
  }
  ot::Spinel::LogIfFail("Set transmit power failed",iVar1);
  return iVar1;
}

