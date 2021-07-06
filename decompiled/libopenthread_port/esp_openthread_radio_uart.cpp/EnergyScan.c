/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> EnergyScan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::EnergyScan(unsigned char, unsigned short) */

int ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::EnergyScan(uchar param_1,ushort param_2)

{
  undefined3 in_register_00002029;
  ulong uVar1;
  int iVar2;
  
  uVar1 = CONCAT31(in_register_00002029,param_1);
  if ((*(byte *)(uVar1 + 0x670) & 2) == 0) {
    iVar2 = 0x1b;
  }
  else {
    iVar2 = Set(uVar1,(char *)0x31);
    if ((iVar2 == 0) && (iVar2 = Set(uVar1,(char *)0x32), iVar2 == 0)) {
      iVar2 = Set(uVar1,(char *)0x30);
    }
  }
  return iVar2;
}

