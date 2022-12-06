/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioReceive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioReceive(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xd;
  if (DAT_00016020 != 0) {
    if (DAT_00015f91 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x15920,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00015f91 = (byte)param_1;
    }
    if ((DAT_00016020 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x15920,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_00015d87;
      if (uVar2 != 0) {
        DAT_00015d87 = 0;
        DAT_00015d84 = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_00015d84;
      }
      DAT_00016020 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

