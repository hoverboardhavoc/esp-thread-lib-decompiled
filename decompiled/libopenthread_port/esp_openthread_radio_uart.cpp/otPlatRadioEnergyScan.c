/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioEnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioEnergyScan(undefined1 param_1,undefined2 param_2)

{
  int iVar1;
  
  if ((DAT_00015f90 & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    DAT_000160c8._1_1_ = DAT_000160c8._1_1_ | 0x80;
    uRam000160c2 = param_1;
    uRam000160c4 = param_2;
    iVar1 = ot::Spinel::
            RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                      (0x15920,(char *)0x31);
    if (((iVar1 == 0) &&
        (iVar1 = ot::Spinel::
                 RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                 ::Set(0x15920,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x15920,(char *)0x30), iVar1 == 0)) {
      DAT_00015f91 = param_1;
    }
  }
  return iVar1;
}

