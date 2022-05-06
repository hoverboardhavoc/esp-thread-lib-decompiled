/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  *(undefined4 *)(this + 0x50) = 0;
  return;
}

