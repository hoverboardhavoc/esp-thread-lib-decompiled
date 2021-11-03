/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
  
  if (DAT_000134c0 != 2) {
    if (DAT_000134c0 != 1) {
      return 0xd;
    }
    if ((DAT_00013430 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00013420 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12dc0,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_000134c0 = 3;
    uVar2 = otPlatTimeGet();
    DAT_000134d0 = uVar2 + 5000000;
    DAT_000134d4 = (uint)(DAT_000134d0 < uVar2) + extraout_a1;
    DAT_00013431 = *(undefined1 *)(DAT_00013420 + 6);
  }
  return iVar1;
}

