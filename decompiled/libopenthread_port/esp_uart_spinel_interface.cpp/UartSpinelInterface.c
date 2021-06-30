/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> UartSpinelInterface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void UartSpinelInterface(UartSpinelInterface * this,
   ReceiveFrameCallback callback, void * callback_context, RxFrameBuffer * frame_buffer) */

void __thiscall
esp::openthread::UartSpinelInterface::UartSpinelInterface
          (UartSpinelInterface *this,ReceiveFrameCallback callback,void *callback_context,
          RxFrameBuffer *frame_buffer)

{
  this->m_receiver_frame_callback = callback;
  this->m_receiver_frame_context = callback_context;
  this->m_receive_frame_buffer = frame_buffer;
  ot::Hdlc::Decoder::Decoder
            (&this->m_hdlc_decoder,&frame_buffer->super_FrameWritePointer,HandleHdlcFrame,this);
  this->m_uart_fd = -1;
  return;
}

