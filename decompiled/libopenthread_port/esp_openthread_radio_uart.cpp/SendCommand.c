/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendCommand
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SendCommand(unsigned long, unsigned long, unsigned char, char
   const*, void*) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SendCommand(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
            *this,ulong param_1,ulong param_2,uchar param_3,char *param_4,void *param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined3 in_register_00002035;
  uchar auStack_534 [1304];
  
  iVar2 = spinel_datatype_pack
                    (auStack_534,0x514,&::_L0,CONCAT31(in_register_00002035,param_3) | 0x80,param_1,
                     param_2);
  if (iVar2 - 1U < 0x514) {
    uVar1 = (ushort)iVar2;
    if (param_4 != (char *)0x0) {
      iVar3 = spinel_datatype_vpack(auStack_534 + iVar2,0x514 - iVar2,param_4,param_5);
      if ((iVar3 < 1) || (0x514 < iVar2 + iVar3)) goto _L262;
      uVar1 = uVar1 + (short)iVar3;
    }
    iVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_534);
    if (iVar2 == 0) {
      LogSpinelFrame(this,auStack_534,uVar1,true);
    }
  }
  else {
_L262:
    iVar2 = 3;
  }
  return iVar2;
}

