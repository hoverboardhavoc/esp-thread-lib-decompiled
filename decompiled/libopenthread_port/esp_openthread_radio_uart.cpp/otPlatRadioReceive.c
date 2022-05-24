/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  if (DAT_00014b28 != 0) {
    if (DAT_00014a99 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x14428,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014a99 = (byte)param_1;
    }
    if ((DAT_00014b28 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14428,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_0001488f;
      if (uVar2 != 0) {
        DAT_0001488f = 0;
        DAT_0001488c = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_0001488c;
      }
      DAT_00014b28 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

