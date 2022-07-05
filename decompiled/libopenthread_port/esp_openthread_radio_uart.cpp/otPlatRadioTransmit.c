/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioTransmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioTransmit(int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  
  if (DAT_00014b88 != 2) {
    if (DAT_00014b88 != 1) {
      return 0xd;
    }
    if ((DAT_00014af8 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014ae8 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x14488,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00014b88 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014c40 = uVar2 + 5000000;
    DAT_00014c44 = (uint)(DAT_00014c40 < uVar2) + extraout_a1;
    DAT_00014af9 = *(undefined1 *)(DAT_00014ae8 + 6);
  }
  return iVar1;
}

