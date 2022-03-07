/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  if (DAT_00013478 != 0) {
    if (DAT_000133e9 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d78,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_000133e9 = (byte)param_1;
    }
    if ((DAT_00013478 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d78,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000131db;
      if (uVar2 != 0) {
        DAT_000131db = 0;
        DAT_000131d8 = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_000131d8;
      }
      DAT_00013478 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

