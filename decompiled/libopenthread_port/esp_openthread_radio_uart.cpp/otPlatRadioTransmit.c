/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  
  if (DAT_000133c0 != 2) {
    if (DAT_000133c0 != 1) {
      return 0xd;
    }
    if ((DAT_00013330 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00013320 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12cc0,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_000133c0 = 3;
    uVar2 = otPlatTimeGet();
    DAT_000133d0 = uVar2 + 5000000;
    DAT_000133d4 = (uint)(DAT_000133d0 < uVar2) + extraout_a1;
    DAT_00013331 = *(undefined1 *)(DAT_00013320 + 6);
  }
  return iVar1;
}

