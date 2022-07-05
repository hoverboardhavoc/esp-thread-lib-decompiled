/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
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
  if (DAT_00014b88 != 0) {
    if (DAT_00014af9 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x14488,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014af9 = (byte)param_1;
    }
    if ((DAT_00014b88 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14488,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000148ef;
      if (uVar2 != 0) {
        DAT_000148ef = 0;
        DAT_000148ec = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_000148ec;
      }
      DAT_00014b88 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

