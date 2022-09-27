/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioReceive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int otPlatRadioReceive(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xd;
  if (DAT_00014c70 != 0) {
    if (DAT_00014be1 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x14570,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014be1 = (byte)param_1;
    }
    if ((DAT_00014c70 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14570,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000149d7;
      if (uVar2 != 0) {
        DAT_000149d7 = 0;
        _DAT_000149d4 = ~(ushort)(1 << (uVar2 & 0x1f)) & _DAT_000149d4;
      }
      DAT_00014c70 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

