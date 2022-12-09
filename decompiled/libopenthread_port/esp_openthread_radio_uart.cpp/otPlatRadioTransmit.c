/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
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
  
  if (DAT_00016020 != 2) {
    if (DAT_00016020 != 1) {
      return 0xd;
    }
    if ((DAT_00015f90 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00015f80 = param_1;
  otPlatRadioTxStarted(s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x15920,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00016020 = 3;
    uVar2 = otPlatTimeGet();
    DAT_000160d8 = uVar2 + 5000000;
    DAT_000160dc = (uint)(DAT_000160d8 < uVar2) + extraout_a1;
    DAT_00015f91 = *(undefined1 *)(DAT_00015f80 + 6);
  }
  return iVar1;
}

