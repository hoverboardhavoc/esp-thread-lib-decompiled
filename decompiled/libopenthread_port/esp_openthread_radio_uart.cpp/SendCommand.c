/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  undefined1 auStack_534 [1304];
  
  iVar1 = spinel_datatype_pack
                    (auStack_534,0x514,&_LC6,CONCAT31(in_register_00002035,param_3) | 0x80,param_1,
                     param_2);
  if ((iVar1 - 1U < 0x514) &&
     ((param_4 == (char *)0x0 ||
      ((iVar3 = spinel_datatype_vpack(auStack_534 + iVar1,0x514 - iVar1,param_4,param_5), 0 < iVar3
       && (iVar1 + iVar3 < 0x515)))))) {
    uVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_534);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

