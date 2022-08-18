/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  
  if (DAT_00014c60 != 2) {
    if (DAT_00014c60 != 1) {
      return 0xd;
    }
    if ((DAT_00014bd0 & 0x10) == 0) {
      return 0xd;
    }
  }
  DAT_00014bc0 = param_1;
  otPlatRadioTxStarted(_s_radio);
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Request(0x14560,3,(char *)0x71);
  if (iVar1 == 0) {
    DAT_00014c60 = 3;
    uVar2 = otPlatTimeGet();
    DAT_00014d18 = uVar2 + 5000000;
    DAT_00014d1c = (uint)(DAT_00014d18 < uVar2) + extraout_a1;
    DAT_00014bd1 = *(undefined1 *)(DAT_00014bc0 + 6);
  }
  return iVar1;
}

