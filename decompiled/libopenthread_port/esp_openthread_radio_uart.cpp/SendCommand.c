/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendCommand
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SendCommand(unsigned long, unsigned long, unsigned char, char
   const*, void*) */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SendCommand(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
            *this,ulong param_1,ulong param_2,uchar param_3,char *param_4,void *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined3 in_register_00002035;
  undefined1 auStack_420 [1028];
  
  iVar1 = spinel_datatype_pack
                    (auStack_420,0x400,&_LC5,CONCAT31(in_register_00002035,param_3) | 0x80,param_1,
                     param_2);
  if ((iVar1 - 1U < 0x400) &&
     ((param_4 == (char *)0x0 ||
      ((iVar3 = spinel_datatype_vpack(auStack_420 + iVar1,0x400 - iVar1,param_4,param_5), 0 < iVar3
       && (iVar1 + iVar3 < 0x401)))))) {
    uVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_420);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

