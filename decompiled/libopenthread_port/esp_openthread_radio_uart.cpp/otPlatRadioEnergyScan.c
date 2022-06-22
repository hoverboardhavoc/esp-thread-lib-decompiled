/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioEnergyScan(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_00014b00 & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    DAT_00014c38._1_1_ = DAT_00014c38._1_1_ | 0x80;
    uRam00014c32 = param_1;
    uRam00014c34 = param_2;
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x14490,(char *)0x31);
    if (((iVar1 == 0) &&
        (iVar1 = ot::Spinel::
                 RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                 ::Set(0x14490,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14490,(char *)0x30), iVar1 == 0)) {
      DAT_00014b01 = param_1;
    }
  }
  return iVar1;
}

