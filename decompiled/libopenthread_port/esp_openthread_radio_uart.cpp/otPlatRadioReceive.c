/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
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
  if (DAT_00014b90 != 0) {
    if (DAT_00014b01 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x14490,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014b01 = (byte)param_1;
    }
    if ((DAT_00014b90 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14490,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000148f7;
      if (uVar2 != 0) {
        DAT_000148f7 = 0;
        DAT_000148f4 = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_000148f4;
      }
      DAT_00014b90 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

