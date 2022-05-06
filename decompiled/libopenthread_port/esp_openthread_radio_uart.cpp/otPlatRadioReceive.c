/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  if (DAT_000143c8 != 0) {
    if (DAT_00014339 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x13cc8,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014339 = (byte)param_1;
    }
    if ((DAT_000143c8 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x13cc8,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_0001412f;
      if (uVar2 != 0) {
        DAT_0001412f = 0;
        DAT_0001412c = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_0001412c;
      }
      DAT_000143c8 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

