/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
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
  
  if (DAT_00014b90 != 2) {
    if (DAT_00014b90 != 1) {
      return 0xd;
    }
    if ((DAT_00014b00 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014af0 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x14490,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00014b90 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014c48 = uVar2 + 5000000;
    DAT_00014c4c = (uint)(DAT_00014c48 < uVar2) + extraout_a1;
    DAT_00014b01 = *(undefined1 *)(DAT_00014af0 + 6);
  }
  return iVar1;
}

