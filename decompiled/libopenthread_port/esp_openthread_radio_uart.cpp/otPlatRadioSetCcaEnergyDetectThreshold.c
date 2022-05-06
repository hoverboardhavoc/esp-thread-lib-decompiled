/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioSetCcaEnergyDetectThreshold
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioSetCcaEnergyDetectThreshold(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x13cc8,(char *)0x24);
  if (iVar1 == 0) {
    DAT_00014470._1_1_ = DAT_00014470._1_1_ | 4;
    DAT_0001446e = param_1;
  }
  ot::Spinel::LogIfFail("Set CCA ED threshold failed",iVar1);
  return iVar1;
}

