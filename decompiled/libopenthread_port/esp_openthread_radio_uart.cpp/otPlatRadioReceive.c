/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  if (DAT_00013408 != 0) {
    if (DAT_00013378._1_1_ != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d08,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00013378._1_1_ = (byte)param_1;
    }
    if ((DAT_00013408 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d08,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_00013168._3_1_;
      if (uVar2 != 0) {
        DAT_00013168._3_1_ = 0;
        DAT_00013168._0_2_ = ~(ushort)(1 << (uVar2 & 0x1f)) & (ushort)DAT_00013168;
      }
      DAT_00013408 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

