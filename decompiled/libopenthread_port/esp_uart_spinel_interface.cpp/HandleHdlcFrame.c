/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> HandleHdlcFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void HandleHdlcFrame(UartSpinelInterface * this, otError error) */

void __thiscall
esp::openthread::UartSpinelInterface::HandleHdlcFrame(UartSpinelInterface *this,otError error)

{
  short sVar1;
  undefined4 uVar2;
  uint8_t *puVar3;
  RxFrameBuffer *pRVar4;
  
  if (error == OT_ERROR_NONE) {
    (*this->m_receiver_frame_callback)(this->m_receiver_frame_context);
  }
  else {
    uVar2 = otThreadErrorToString(error);
    otLogCrit(0xc,"-PLAT----: ","dropping radio frame: %s",uVar2);
    pRVar4 = this->m_receive_frame_buffer;
    puVar3 = pRVar4->mWriteFrameStart;
    sVar1 = (short)&pRVar4->field_0x406;
    if (puVar3 + 4 <= &pRVar4->field_0x406) {
      puVar3[2] = '\0';
      puVar3[3] = '\0';
      puVar3 = pRVar4->mWriteFrameStart + *(ushort *)(pRVar4->mWriteFrameStart + 2) + 4;
      (pRVar4->super_FrameWritePointer).mWritePointer = puVar3;
      (pRVar4->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar3;
    }
    puVar3 = pRVar4->mWriteFrameStart + *(ushort *)(pRVar4->mWriteFrameStart + 2) + 4;
    (pRVar4->super_FrameWritePointer).mWritePointer = puVar3;
    (pRVar4->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar3;
  }
  return;
}

