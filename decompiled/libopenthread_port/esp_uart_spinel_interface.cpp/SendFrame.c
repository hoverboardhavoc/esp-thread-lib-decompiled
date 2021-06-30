/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> SendFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* WARNING: Struct "FrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError SendFrame(UartSpinelInterface * this, uint8_t * frame, uint16_t
   length) */

otError __thiscall
esp::openthread::UartSpinelInterface::SendFrame
          (UartSpinelInterface *this,uint8_t *frame,uint16_t length)

{
  otError oVar1;
  uint8_t *aFrame;
  undefined1 auStack_430 [4];
  Encoder hdlc_encoder;
  FrameBuffer<1024> encoder_buffer;
  
  hdlc_encoder._4_4_ = (int)&encoder_buffer.super_FrameWritePointer.mWritePointer + 2;
  encoder_buffer.super_FrameWritePointer.mWritePointer._0_2_ = 0x400;
  ot::Hdlc::Encoder::Encoder((Encoder *)auStack_430,(FrameWritePointer *)&hdlc_encoder.mFcs);
  oVar1 = ot::Hdlc::Encoder::BeginFrame();
  if (((oVar1 == OT_ERROR_NONE) &&
      (oVar1 = ot::Hdlc::Encoder::Encode(auStack_430,(ushort)frame), oVar1 == OT_ERROR_NONE)) &&
     (oVar1 = ot::Hdlc::Encoder::EndFrame(), oVar1 == OT_ERROR_NONE)) {
    aFrame = (uint8_t *)((int)&encoder_buffer.super_FrameWritePointer.mWritePointer + 2);
    oVar1 = Write(this,aFrame,(uint16_t)hdlc_encoder._4_4_ - (short)aFrame);
  }
  if (oVar1 != OT_ERROR_NONE) {
    otLogCrit(0xc,"-PLAT----: ","send radio frame failed");
  }
  return oVar1;
}

