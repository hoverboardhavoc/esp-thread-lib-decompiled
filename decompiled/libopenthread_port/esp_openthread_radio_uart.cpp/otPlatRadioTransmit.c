/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  
  if (DAT_00013478 != 2) {
    if (DAT_00013478 != 1) {
      return 0xd;
    }
    if ((DAT_000133e8 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_000133d8 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12d78,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00013478 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00013488 = uVar2 + 5000000;
    DAT_0001348c = (uint)(DAT_00013488 < uVar2) + extraout_a1;
    DAT_000133e9 = *(undefined1 *)(DAT_000133d8 + 6);
  }
  return iVar1;
}

