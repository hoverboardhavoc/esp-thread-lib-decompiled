/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   SendReset(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
SendReset(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this
         )

{
  int iVar1;
  otError oVar2;
  undefined1 auStack_410 [4];
  uint8_t buffer [1024];
  
  iVar1 = spinel_datatype_pack(auStack_410,0x400,&_LC3,0x80,1);
  if (iVar1 - 1U < 0x400) {
    oVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)&this->mSpinelInterface,(ushort)auStack_410);
  }
  else {
    oVar2 = OT_ERROR_NO_BUFS;
  }
  return oVar2;
}

