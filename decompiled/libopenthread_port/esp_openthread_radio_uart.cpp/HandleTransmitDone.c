/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleTransmitDone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleTransmitDone(unsigned long, unsigned long, unsigned
   char const*, unsigned short) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleTransmitDone(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this,ulong param_1,ulong param_2,uchar *param_3,ushort param_4)

{
  uint uVar1;
  uint uVar2;
  uchar *puVar3;
  ulong extraout_a1;
  undefined2 in_register_0000203a;
  int iVar4;
  undefined1 uStack_2f;
  byte bStack_2e;
  undefined1 uStack_2d;
  Spinel *pSStack_2c;
  int iStack_28;
  undefined1 auStack_24 [12];
  
  pSStack_2c = (Spinel *)0x0;
  uStack_2f = 0;
  bStack_2e = 0;
  iVar4 = 1;
  if ((param_1 != 6) || (param_2 != 0)) goto _L0;
  iStack_28 = spinel_datatype_unpack
                        (param_3,CONCAT22(in_register_0000203a,param_4),&_LC10,&pSStack_2c);
  if (0 < iStack_28) {
    puVar3 = param_3 + iStack_28;
    uVar1 = CONCAT22(in_register_0000203a,param_4) - iStack_28 & 0xffff;
    iStack_28 = spinel_datatype_unpack(puVar3,uVar1,&_LC34,&uStack_2f);
    if (0 < iStack_28) {
      puVar3 = puVar3 + iStack_28;
      uVar1 = uVar1 - iStack_28 & 0xffff;
      iStack_28 = spinel_datatype_unpack(puVar3,uVar1,&_LC34,&bStack_2e);
      if (0 < iStack_28) {
        uVar1 = uVar1 - iStack_28;
        puVar3 = puVar3 + iStack_28;
        uVar2 = uVar1 & 0xffff;
        if (pSStack_2c == (Spinel *)0x0) {
          iVar4 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x640),puVar3,(ushort)uVar1,
                                  &iStack_28);
          if (iVar4 != 0) goto _L0;
          puVar3 = puVar3 + iStack_28;
          uVar2 = uVar2 - iStack_28 & 0xffff;
        }
        else {
          iVar4 = SpinelStatusToOtError(pSStack_2c,extraout_a1);
        }
        *(byte *)(*(int *)(this + 0x660) + 0x1a) =
             *(byte *)(*(int *)(this + 0x660) + 0x1a) & 0xfe | bStack_2e & 1;
        if (((((byte)this[0x670] & 0x20) == 0) || (bStack_2e == 0)) ||
           ((*(byte *)**(undefined4 **)(this + 0x660) & 8) == 0)) goto _L0;
        iStack_28 = spinel_datatype_unpack(puVar3,uVar2,&_LC50,&uStack_2d,auStack_24);
        if (0 < iStack_28) {
          ot::Mac::Frame::SetKeyId((uchar)*(undefined4 *)(this + 0x660));
          ot::Mac::Frame::SetFrameCounter(*(ulong *)(this + 0x660));
          goto _L0;
        }
      }
    }
  }
  iVar4 = 6;
_L0:
  *(int *)(this + 0x674) = iVar4;
  *(undefined4 *)(this + 0x700) = 4;
  LogIfFail("Handle transmit done failed",iVar4);
  return;
}

