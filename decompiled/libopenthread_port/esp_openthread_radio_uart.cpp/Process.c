/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   Process(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, esp_openthread_mainloop_context_t * aContext) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
Process(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
       esp_openthread_mainloop_context_t *aContext)

{
  undefined1 *puVar1;
  
  puVar1 = &(this->mRxFrameBuffer).super_FrameWritePointer.field_0x6;
  if (puVar1 != (this->mRxFrameBuffer).mWriteFrameStart) {
    ProcessFrameQueue(this);
  }
  esp::openthread::UartSpinelInterface::Process
            ((esp_openthread_mainloop_context_t *)&this->mSpinelInterface);
  if ((this->mRxFrameBuffer).mWriteFrameStart != puVar1) {
    ProcessFrameQueue(this);
  }
  ProcessRadioStateMachine(this);
  CalcRcpTimeOffset(this);
  return;
}

