/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestWithPropertyFormat
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   RequestWithPropertyFormat(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, char * aPropertyFormat, uint32_t aCommand, spinel_prop_key_t aKey, char * aFormat, ...)
    */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
RequestWithPropertyFormat
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this,char *aPropertyFormat,uint32_t aCommand,spinel_prop_key_t aKey,char *aFormat,...)

{
  otError oVar1;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  va_list args;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  oVar1 = RequestWithPropertyFormatV(this,aPropertyFormat,aCommand,aKey,aFormat,&uStack_c);
  return oVar1;
}

