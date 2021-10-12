/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  
  if (DAT_00013408 != 2) {
    if (DAT_00013408 != 1) {
      return 0xd;
    }
    if (((byte)DAT_00013378 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00013368 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12d08,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00013408 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00013418 = uVar2 + 5000000;
    DAT_0001341c = (uint)(DAT_00013418 < uVar2) + extraout_a1;
    DAT_00013378._1_1_ = *(undefined1 *)(DAT_00013368 + 6);
  }
  return iVar1;
}

