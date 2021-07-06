/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SendReset() */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SendReset(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_410 [1032];
  
  iVar1 = spinel_datatype_pack(auStack_410,0x400,&_LC3,0x80,1);
  if (iVar1 - 1U < 0x400) {
    uVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_410);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

