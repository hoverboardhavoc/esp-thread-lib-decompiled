/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
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
  if (DAT_000133d0 != 0) {
    if (DAT_00013341 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12cd0,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00013341 = (byte)param_1;
    }
    if ((DAT_000133d0 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12cd0,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_00013130._3_1_;
      if (uVar2 != 0) {
        DAT_00013130._3_1_ = 0;
        DAT_00013130._0_2_ = ~(ushort)(1 << (uVar2 & 0x1f)) & (ushort)DAT_00013130;
      }
      DAT_000133d0 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

