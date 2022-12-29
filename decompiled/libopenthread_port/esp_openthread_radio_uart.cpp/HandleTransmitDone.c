/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  undefined4 *puVar4;
  int iVar5;
  undefined1 uStack_2f;
  byte local_2e;
  undefined1 uStack_2d;
  Spinel *pSStack_2c;
  int iStack_28;
  undefined1 auStack_24 [12];
  
  pSStack_2c = (Spinel *)0x0;
  uStack_2f = 0;
  local_2e = 0;
  iVar5 = 1;
  if ((param_1 != 6) || (param_2 != 0)) goto _L0;
  iStack_28 = spinel_datatype_unpack
                        (param_3,CONCAT22(in_register_0000203a,param_4),&_LC30,&pSStack_2c);
  if (0 < iStack_28) {
    puVar3 = param_3 + iStack_28;
    uVar1 = CONCAT22(in_register_0000203a,param_4) - iStack_28 & 0xffff;
    iStack_28 = spinel_datatype_unpack(puVar3,uVar1,&_LC32,&uStack_2f);
    if (0 < iStack_28) {
      puVar3 = puVar3 + iStack_28;
      uVar1 = uVar1 - iStack_28 & 0xffff;
      iStack_28 = spinel_datatype_unpack(puVar3,uVar1,&_LC32,&local_2e);
      if (0 < iStack_28) {
        uVar1 = uVar1 - iStack_28;
        puVar3 = puVar3 + iStack_28;
        uVar2 = uVar1 & 0xffff;
        if (pSStack_2c == (Spinel *)0x0) {
          iVar5 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x640),puVar3,(ushort)uVar1,
                                  &iStack_28);
          if (iVar5 != 0) goto _L0;
          puVar3 = puVar3 + iStack_28;
          uVar2 = uVar2 - iStack_28 & 0xffff;
        }
        else {
          iVar5 = SpinelStatusToOtError(pSStack_2c,extraout_a1);
        }
        puVar4 = *(undefined4 **)(this + 0x660);
        *(byte *)((int)puVar4 + 0x1a) = *(byte *)((int)puVar4 + 0x1a) & 0xfe | local_2e & 1;
        if (((((byte)this[0x670] & 0x20) == 0) || (local_2e == 0)) || ((*(byte *)*puVar4 & 8) == 0))
        goto _L0;
        iStack_28 = spinel_datatype_unpack(puVar3,uVar2,&_LC156,&uStack_2d,auStack_24);
        if (0 < iStack_28) {
          ot::Mac::Frame::SetKeyId((uchar)*(undefined4 *)(this + 0x660));
          ot::Mac::Frame::SetFrameCounter(*(ulong *)(this + 0x660));
          goto _L0;
        }
      }
    }
  }
  iVar5 = 6;
_L0:
  *(undefined4 *)(this + 0x700) = 4;
  *(int *)(this + 0x674) = iVar5;
  UpdateParseErrorCount(this,iVar5);
  LogIfFail("Handle transmit done failed",iVar5);
  return;
}

