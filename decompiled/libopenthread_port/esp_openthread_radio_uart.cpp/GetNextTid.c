/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetNextTid
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: spinel_tid_t
   GetNextTid(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this) */

spinel_tid_t __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
GetNextTid(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this)

{
  spinel_tid_t sVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = this->mCmdNextTid;
  uVar3 = (uint)bVar2;
  if (((int)(uint)this->mCmdTidsInUse >> (uVar3 & 0x1f) & 1U) == 0) {
    if (uVar3 < 0xf) {
      sVar1 = bVar2 + 1;
    }
    else {
      sVar1 = '\x01';
    }
    this->mCmdNextTid = sVar1;
    this->mCmdTidsInUse = this->mCmdTidsInUse | (ushort)(1 << (uVar3 & 0x1f));
  }
  else {
    bVar2 = 0;
  }
  return bVar2;
}

