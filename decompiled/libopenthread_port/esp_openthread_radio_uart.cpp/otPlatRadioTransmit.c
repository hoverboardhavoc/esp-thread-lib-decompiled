/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  
  if (DAT_000143c8 != 2) {
    if (DAT_000143c8 != 1) {
      return 0xd;
    }
    if ((DAT_00014338 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014328 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x13cc8,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_000143c8 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014480 = uVar2 + 5000000;
    DAT_00014484 = (uint)(DAT_00014480 < uVar2) + extraout_a1;
    DAT_00014339 = *(undefined1 *)(DAT_00014328 + 6);
  }
  return iVar1;
}

