/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
  
  if (DAT_00014c70 != 2) {
    if (DAT_00014c70 != 1) {
      return 0xd;
    }
    if ((DAT_00014be0 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014bd0 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x14570,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00014c70 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014d28 = uVar2 + 5000000;
    DAT_00014d2c = (uint)(DAT_00014d28 < uVar2) + extraout_a1;
    DAT_00014be1 = *(undefined1 *)(DAT_00014bd0 + 6);
  }
  return iVar1;
}

