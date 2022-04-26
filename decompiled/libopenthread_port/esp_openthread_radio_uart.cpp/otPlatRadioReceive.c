/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioReceive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioReceive(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xd;
  if (DAT_00013490 != 0) {
    if (DAT_00013401 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x12d90,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00013401 = (byte)param_1;
    }
    if ((DAT_00013490 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x12d90,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000131f3;
      if (uVar2 != 0) {
        DAT_000131f3 = 0;
        DAT_000131f0 = ~(ushort)(1 << (uVar2 & 0x1f)) & DAT_000131f0;
      }
      DAT_00013490 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

