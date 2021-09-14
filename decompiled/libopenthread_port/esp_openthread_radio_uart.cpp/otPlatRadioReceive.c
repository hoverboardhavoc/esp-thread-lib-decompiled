/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  if (DAT_000133c0 != 0) {
    if (DAT_00013331 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12cc0,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00013331 = (byte)param_1;
    }
    if ((DAT_000133c0 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12cc0,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_00013123;
      if (uVar2 != 0) {
        DAT_00013123 = 0;
        DAT_00013120 = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_00013120;
      }
      DAT_000133c0 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

