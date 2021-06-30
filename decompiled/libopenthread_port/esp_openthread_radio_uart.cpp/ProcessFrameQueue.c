/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ProcessFrameQueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   ProcessFrameQueue(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
ProcessFrameQueue(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                  *this)

{
  uint8_t *puVar1;
  ushort *puVar2;
  uint uVar3;
  undefined1 *__dest;
  int iVar4;
  uint8_t *puVar5;
  
  uVar3 = 0;
  puVar1 = (uint8_t *)0x0;
  while( true ) {
    if ((puVar1 != (uint8_t *)0x0) &&
       ((puVar1 < &(this->mRxFrameBuffer).super_FrameWritePointer.field_0x6 ||
        (&(this->mRxFrameBuffer).field_0x406 <= puVar1)))) {
      otPlatAssertFail("IDF/components/openthread/openthread/src/lib/hdlc/hdlc.hpp",0x171);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (puVar1 == (uint8_t *)0x0) {
      puVar2 = (ushort *)&(this->mRxFrameBuffer).super_FrameWritePointer.field_0x6;
    }
    else {
      puVar2 = (ushort *)(puVar1 + uVar3);
    }
    if (puVar2 == (ushort *)(this->mRxFrameBuffer).mWriteFrameStart) {
      uVar3 = 0;
      puVar1 = (uint8_t *)0x0;
      iVar4 = 0x17;
    }
    else {
      uVar3 = (uint)*puVar2 - (uint)puVar2[1] & 0xffff;
      puVar1 = (uint8_t *)((int)puVar2 + puVar2[1] + 4);
      iVar4 = 0;
    }
    if (iVar4 != 0) break;
    HandleNotification(this,puVar1,(uint16_t)uVar3);
  }
  puVar1 = (this->mRxFrameBuffer).mWriteFrameStart;
  __dest = &(this->mRxFrameBuffer).super_FrameWritePointer.field_0x6;
  uVar3 = (int)puVar1 - (int)__dest;
  if ((uVar3 & 0xffff) != 0) {
    puVar5 = (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer;
    memmove(__dest,puVar1,(int)puVar5 - (int)puVar1 & 0xffff);
    (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar5 + -(uVar3 & 0xffff);
    (this->mRxFrameBuffer).mWriteFrameStart =
         (this->mRxFrameBuffer).mWriteFrameStart + -(uVar3 & 0xffff);
    (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength =
         (short)(uVar3 * 0x10000 >> 0x10) +
         (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength;
  }
  return;
}

