/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleReceivedFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleReceivedFrame(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleReceivedFrame(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                    *this)

{
  short sVar1;
  uint8_t *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  byte abStack_11 [4];
  uint8_t header;
  
  puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
  iVar3 = spinel_datatype_unpack
                    ((int)(this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer -
                     (int)(puVar2 + *(ushort *)(puVar2 + 2) + 4) & 0xffff,&_LC38,abStack_11);
  if (((0 < iVar3) && ((char)abStack_11[0] < '\0')) && (((int)(uint)abStack_11[0] >> 4 & 3U) == 0))
  {
    if ((abStack_11[0] & 0xf) == 0) {
      HandleNotification(this,&this->mRxFrameBuffer);
      return;
    }
    puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
    puVar2 = puVar2 + *(ushort *)(puVar2 + 2) + 4;
    HandleResponse(this,puVar2,
                   (short)(this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer -
                   (short)puVar2);
    puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
    puVar5 = &(this->mRxFrameBuffer).field_0x406;
    sVar1 = (short)puVar5;
    if (puVar2 + 4 <= puVar5) {
      puVar2[2] = '\0';
      puVar2[3] = '\0';
      puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
      puVar2 = puVar2 + *(ushort *)(puVar2 + 2) + 4;
      (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar2;
      (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength = sVar1 - (short)puVar2;
    }
    puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
    puVar2 = puVar2 + *(ushort *)(puVar2 + 2) + 4;
    (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar2;
    (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength = sVar1 - (short)puVar2;
    return;
  }
  puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
  puVar5 = &(this->mRxFrameBuffer).field_0x406;
  sVar1 = (short)puVar5;
  if (puVar2 + 4 <= puVar5) {
    puVar2[2] = '\0';
    puVar2[3] = '\0';
    puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
    puVar2 = puVar2 + *(ushort *)(puVar2 + 2) + 4;
    (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar2;
    (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength = sVar1 - (short)puVar2;
  }
  puVar2 = (this->mRxFrameBuffer).mWriteFrameStart;
  puVar2 = puVar2 + *(ushort *)(puVar2 + 2) + 4;
  (this->mRxFrameBuffer).super_FrameWritePointer.mWritePointer = puVar2;
  (this->mRxFrameBuffer).super_FrameWritePointer.mRemainingLength = sVar1 - (short)puVar2;
  uVar4 = otThreadErrorToString(6);
  otLogWarn(0xc,_LC2,"Error handling hdlc frame: %s",uVar4);
  return;
}

