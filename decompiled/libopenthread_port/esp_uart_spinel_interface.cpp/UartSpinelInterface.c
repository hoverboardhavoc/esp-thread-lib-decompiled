/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  *(void **)(this + 4) = param_2;
  *(_func_void_void_ptr **)this = param_1;
  *(MultiFrameBuffer **)(this + 8) = param_3;
  ot::Hdlc::Decoder::Decoder
            ((Decoder *)(this + 0xc),(FrameWritePointer *)param_3,HandleHdlcFrame,this);
  *(undefined4 *)(this + 0x4c) = 0xffffffff;
  *(undefined4 *)(this + 0x50) = 0;
  return;
}

