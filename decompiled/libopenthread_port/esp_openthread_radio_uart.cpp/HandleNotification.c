/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleNotification
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, RxFrameBuffer * aFrameBuffer) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this,RxFrameBuffer *aFrameBuffer)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint8_t *puVar4;
  byte bStack_21;
  uint uStack_20;
  uint8_t header;
  uint32_t cmd;
  uint8_t *data;
  spinel_size_t len;
  spinel_prop_key_t key;
  
  data = (uint8_t *)0x0;
  cmd = 0;
  iVar2 = spinel_datatype_unpack
                    ((int)(aFrameBuffer->super_FrameWritePointer).mWritePointer -
                     (int)(aFrameBuffer->mWriteFrameStart +
                          *(ushort *)(aFrameBuffer->mWriteFrameStart + 2) + 4) & 0xffff,&_LC58,
                     &bStack_21,&stack0xffffffe0,&len,&cmd,&data);
  if (iVar2 < 1) {
    iVar2 = 6;
  }
  else if ((bStack_21 & 0xf) == 0) {
    if (uStack_20 == 6) {
      if ((len == 0x71) || (len == 0x39)) {
        puVar4 = aFrameBuffer->mWriteFrameStart;
        iVar2 = (uint)*(ushort *)(puVar4 + 2) +
                ((int)(aFrameBuffer->super_FrameWritePointer).mWritePointer -
                 (int)(puVar4 + *(ushort *)(puVar4 + 2) + 4) & 0xffffU);
        *puVar4 = (uint8_t)((uint)(iVar2 * 0x10000) >> 0x10);
        puVar4[1] = (uint8_t)((uint)iVar2 >> 8);
        puVar4 = (aFrameBuffer->super_FrameWritePointer).mWritePointer;
        aFrameBuffer->mWriteFrameStart = puVar4;
        sVar1 = (short)&aFrameBuffer->field_0x406;
        if (puVar4 + 4 <= &aFrameBuffer->field_0x406) {
          puVar4[2] = '\0';
          puVar4[3] = '\0';
          puVar4 = aFrameBuffer->mWriteFrameStart +
                   *(ushort *)(aFrameBuffer->mWriteFrameStart + 2) + 4;
          (aFrameBuffer->super_FrameWritePointer).mWritePointer = puVar4;
          (aFrameBuffer->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar4;
        }
        puVar4 = aFrameBuffer->mWriteFrameStart +
                 *(ushort *)(aFrameBuffer->mWriteFrameStart + 2) + 4;
        (aFrameBuffer->super_FrameWritePointer).mWritePointer = puVar4;
        (aFrameBuffer->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar4;
        iVar2 = 0;
        goto _L0;
      }
      HandleValueIs(this,len,(uint8_t *)cmd,(uint16_t)data);
      iVar2 = 0;
    }
    else if (uStack_20 < 6) {
      iVar2 = 6;
    }
    else if (uStack_20 < 9) {
      otLogInfo(0xc,_LC2,"Ignored command %d");
      iVar2 = 0;
    }
    else {
      iVar2 = 6;
    }
  }
  else {
    iVar2 = 6;
  }
  puVar4 = aFrameBuffer->mWriteFrameStart;
  sVar1 = (short)&aFrameBuffer->field_0x406;
  if (puVar4 + 4 <= &aFrameBuffer->field_0x406) {
    puVar4[2] = '\0';
    puVar4[3] = '\0';
    puVar4 = aFrameBuffer->mWriteFrameStart + *(ushort *)(aFrameBuffer->mWriteFrameStart + 2) + 4;
    (aFrameBuffer->super_FrameWritePointer).mWritePointer = puVar4;
    (aFrameBuffer->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar4;
  }
  puVar4 = aFrameBuffer->mWriteFrameStart + *(ushort *)(aFrameBuffer->mWriteFrameStart + 2) + 4;
  (aFrameBuffer->super_FrameWritePointer).mWritePointer = puVar4;
  (aFrameBuffer->super_FrameWritePointer).mRemainingLength = sVar1 - (short)puVar4;
_L0:
  if (iVar2 != 0) {
    uVar3 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing notification",uVar3);
  }
  return;
}

