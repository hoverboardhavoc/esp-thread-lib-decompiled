/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  
  if (DAT_000160b0 != 2) {
    if (DAT_000160b0 != 1) {
      return 0xd;
    }
    if ((DAT_00016020 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00016010 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x159b0,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_000160b0 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00016168 = uVar2 + 5000000;
    DAT_0001616c = (uint)(DAT_00016168 < uVar2) + extraout_a1;
    DAT_00016021 = *(undefined1 *)(DAT_00016010 + 6);
  }
  return iVar1;
}

