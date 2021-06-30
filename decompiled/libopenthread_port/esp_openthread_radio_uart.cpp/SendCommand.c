/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendCommand
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   SendCommand(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint32_t aCommand, spinel_prop_key_t aKey, spinel_tid_t tid, char * aFormat, va_list
   args) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
SendCommand(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
            *this,uint32_t aCommand,spinel_prop_key_t aKey,spinel_tid_t tid,char *aFormat,
           va_list args)

{
  uint uVar1;
  int iVar2;
  otError oVar3;
  undefined3 in_register_00002035;
  undefined1 auStack_420 [4];
  uint8_t buffer [1024];
  
  uVar1 = spinel_datatype_pack
                    (auStack_420,0x400,&_LC8,CONCAT31(in_register_00002035,tid) | 0x80,aCommand,aKey
                    );
  if (0x3ff < uVar1 - 1) {
    return OT_ERROR_NO_BUFS;
  }
  uVar1 = uVar1 & 0xffff;
  if (aFormat != (char *)0x0) {
    iVar2 = spinel_datatype_vpack(auStack_420 + uVar1,0x400 - uVar1,aFormat,args);
    if (iVar2 < 1) {
      return OT_ERROR_NO_BUFS;
    }
    if (0x400 < uVar1 + iVar2) {
      return OT_ERROR_NO_BUFS;
    }
  }
  oVar3 = esp::openthread::UartSpinelInterface::SendFrame
                    ((uchar *)&this->mSpinelInterface,(ushort)auStack_420);
  return oVar3;
}

