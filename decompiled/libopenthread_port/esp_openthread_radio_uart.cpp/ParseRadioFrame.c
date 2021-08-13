/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ParseRadioFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000129ee) */
/* WARNING: Removing unreachable block (ram,0x000129f6) */
/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ParseRadioFrame(otRadioFrame&, unsigned char const*, unsigned
   short, int&) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
ParseRadioFrame(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *this,otRadioFrame *param_1,uchar *param_2,ushort param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 in_register_00002036;
  int iStack_2c;
  undefined4 uStack_28;
  undefined1 uStack_23;
  ushort auStack_22 [5];
  
  iVar2 = CONCAT22(in_register_00002036,param_3);
  auStack_22[0] = 0;
  uStack_23 = 0x80;
  uStack_28 = 0x7f;
  iStack_2c = 0;
  if (iVar2 == 0) {
    *(undefined2 *)(param_1 + 4) = 0;
    iStack_2c = 0;
  }
  else {
    uVar1 = spinel_datatype_unpack_in_place
                      (param_2,iVar2,"dccSt(CCX)t(i)",*(undefined4 *)param_1,&uStack_28,
                       param_1 + 0x15,&uStack_23,auStack_22);
    if ((int)uVar1 < 1) {
      iStack_2c = 6;
    }
    else {
      *param_4 = uVar1;
      if (((byte)this[0x670] & 0x20) != 0) {
        iVar2 = spinel_datatype_unpack_in_place
                          (param_2 + uVar1,iVar2 - (uVar1 & 0xffff) & 0xffff,"t(CL)",param_1 + 0x14,
                           param_1 + 0x10);
        if (iVar2 < 1) {
          iStack_2c = 6;
          goto _L0;
        }
        *param_4 = iVar2 + *param_4;
      }
      *(ushort *)(param_1 + 4) = (ushort)(byte)uStack_28;
      param_1[0x17] =
           (otRadioFrame)
           ((byte)param_1[0x17] & 0xfc | (byte)(auStack_22[0] >> 4) & 1 |
           (byte)((auStack_22[0] >> 5 & 1) << 1));
    }
  }
_L0:
  if (iStack_2c != 0) {
    uVar3 = otThreadErrorToString(iStack_2c);
    otLogWarn(0xc,_LC3,"%s: %s","Handle radio frame failed",uVar3);
  }
  return iStack_2c;
}

