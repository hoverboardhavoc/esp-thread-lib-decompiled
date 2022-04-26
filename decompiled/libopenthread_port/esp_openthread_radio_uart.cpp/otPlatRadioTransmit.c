/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  
  if (DAT_00013490 != 2) {
    if (DAT_00013490 != 1) {
      return 0xd;
    }
    if ((DAT_00013400 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_000133f0 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x12d90,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00013490 = 3;
    uVar2 = otPlatTimeGet();
    DAT_000134a0 = uVar2 + 5000000;
    DAT_000134a4 = (uint)(DAT_000134a0 < uVar2) + extraout_a1;
    DAT_00013401 = *(undefined1 *)(DAT_000133f0 + 6);
  }
  return iVar1;
}

