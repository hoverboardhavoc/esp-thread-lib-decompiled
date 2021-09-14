/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ParseRadioFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ParseRadioFrame(otRadioFrame&, unsigned char const*, unsigned
   short, int&) */

uint __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
ParseRadioFrame(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *this,otRadioFrame *param_1,uchar *param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined2 in_register_00002036;
  undefined1 uStack_2b;
  ushort uStack_2a;
  undefined4 uStack_28;
  uint uStack_24;
  
  iVar3 = CONCAT22(in_register_00002036,param_3);
  uStack_2b = 0x80;
  uStack_2a = 0;
  uStack_28 = 0x7f;
  uStack_24 = 0;
  if (iVar3 == 0) {
    *(undefined2 *)(param_1 + 4) = 0;
    uVar1 = 0;
    goto _L0;
  }
  iVar2 = spinel_datatype_unpack_in_place
                    (param_2,iVar3,"dccSt(CCX)t(i)",*(undefined4 *)param_1,&uStack_28,param_1 + 0x15
                     ,&uStack_2b,&uStack_2a);
  if (0 < iVar2) {
    *param_4 = iVar2;
    if (((byte)this[0x670] & 0x20) != 0) {
      iVar3 = spinel_datatype_unpack_in_place
                        (param_2 + iVar2,iVar3 - iVar2 & 0xffff,"t(CL)",param_1 + 0x14,
                         param_1 + 0x10);
      if (iVar3 < 1) goto _L0;
      *param_4 = *param_4 + iVar3;
    }
    uVar1 = uStack_24;
    if (uStack_24 == 0) {
      *(ushort *)(param_1 + 4) = (ushort)(byte)uStack_28;
      param_1[0x17] =
           (otRadioFrame)
           ((byte)param_1[0x17] & 0xfc | (byte)(uStack_2a >> 4) & 1 | (byte)(uStack_2a >> 4) & 2);
      goto _L0;
    }
    if (uStack_24 < 0x26) goto _L0;
  }
_L0:
  uVar1 = 6;
_L0:
  LogIfFail("Handle radio frame failed",uVar1);
  return uVar1;
}

