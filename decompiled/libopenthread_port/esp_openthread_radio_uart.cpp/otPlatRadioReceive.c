/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioReceive
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int otPlatRadioReceive(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0xd;
  if (DAT_00014c60 != 0) {
    if (DAT_00014bd1 != param_1) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Set(0x14560,(char *)0x21);
      if (iVar1 != 0) {
        return iVar1;
      }
      DAT_00014bd1 = (byte)param_1;
    }
    if ((DAT_00014c60 != 1) ||
       (iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::Set(0x14560,(char *)0x37), iVar1 == 0)) {
      uVar2 = (uint)DAT_000149c7;
      if (uVar2 != 0) {
        DAT_000149c7 = 0;
        _DAT_000149c4 = ~(ushort)(1 << (uVar2 & 0x1f)) & _DAT_000149c4;
      }
      DAT_00014c60 = 2;
      iVar1 = 0;
    }
  }
  return iVar1;
}

