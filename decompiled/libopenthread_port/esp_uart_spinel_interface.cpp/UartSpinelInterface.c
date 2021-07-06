/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> UartSpinelInterface
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::UartSpinelInterface(void (*)(void*), void*,
   ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>&) */

void __thiscall
esp::openthread::UartSpinelInterface::UartSpinelInterface
          (UartSpinelInterface *this,_func_void_void_ptr *param_1,void *param_2,
          MultiFrameBuffer *param_3)

{
  *(_func_void_void_ptr **)this = param_1;
  *(void **)(this + 4) = param_2;
  *(MultiFrameBuffer **)(this + 8) = param_3;
  ot::Hdlc::Decoder::Decoder
            ((Decoder *)(this + 0xc),(FrameWritePointer *)param_3,HandleHdlcFrame,this);
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  return;
}

