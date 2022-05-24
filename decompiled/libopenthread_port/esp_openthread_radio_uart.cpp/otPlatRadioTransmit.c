/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioTransmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int otPlatRadioTransmit(int param_1)

{
  int iVar1;
  uint uVar2;
  int extraout_a1;
  
  if (DAT_00014b28 != 2) {
    if (DAT_00014b28 != 1) {
      return 0xd;
    }
    if ((DAT_00014a98 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014a88 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x14428,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00014b28 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014be0 = uVar2 + 5000000;
    DAT_00014be4 = (uint)(DAT_00014be0 < uVar2) + extraout_a1;
    DAT_00014a99 = *(undefined1 *)(DAT_00014a88 + 6);
  }
  return iVar1;
}

