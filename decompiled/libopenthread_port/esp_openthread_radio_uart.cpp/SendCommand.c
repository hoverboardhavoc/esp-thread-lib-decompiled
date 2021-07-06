/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined3 in_register_00002035;
  undefined1 auStack_420 [1032];
  
  uVar1 = spinel_datatype_pack
                    (auStack_420,0x400,&_LC8,CONCAT31(in_register_00002035,param_3) | 0x80,param_1,
                     param_2);
  if (0x3ff < uVar1 - 1) {
    return 3;
  }
  uVar1 = uVar1 & 0xffff;
  if (param_4 != (char *)0x0) {
    iVar2 = spinel_datatype_vpack(auStack_420 + uVar1,0x400 - uVar1,param_4,param_5);
    if (iVar2 < 1) {
      return 3;
    }
    if (0x400 < uVar1 + iVar2) {
      return 3;
    }
  }
  uVar3 = esp::openthread::UartSpinelInterface::SendFrame
                    ((uchar *)(this + 0x410),(ushort)auStack_420);
  return uVar3;
}

