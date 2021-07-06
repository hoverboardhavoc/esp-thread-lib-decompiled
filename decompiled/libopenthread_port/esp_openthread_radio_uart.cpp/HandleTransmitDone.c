/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  undefined4 uVar3;
  undefined2 in_register_0000203a;
  uint uVar4;
  uint uVar5;
  uchar *puVar6;
  undefined1 uStack_31;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  undefined1 uStack_25;
  uint auStack_24 [3];
  
  auStack_24[0] = 0;
  uStack_25 = 0;
  if (param_1 == 6) {
    if (param_2 == 0) {
      uStack_2c = spinel_datatype_unpack
                            (param_3,CONCAT22(in_register_0000203a,param_4),&_LC14,auStack_24);
      uVar1 = 6;
      uVar2 = uVar1;
      if (0 < (int)uStack_2c) {
        puVar6 = param_3 + uStack_2c;
        uVar4 = CONCAT22(in_register_0000203a,param_4) - (uStack_2c & 0xffff) & 0xffff;
        uStack_2c = spinel_datatype_unpack(puVar6,uVar4,&_LC39,&uStack_25);
        if (0 < (int)uStack_2c) {
          puVar6 = puVar6 + uStack_2c;
          uVar4 = uVar4 - (uStack_2c & 0xffff);
          uVar5 = uVar4 & 0xffff;
          if (auStack_24[0] == 0) {
            uVar2 = ParseRadioFrame(this,(otRadioFrame *)(this + 0x640),puVar6,(ushort)uVar4,
                                    (int *)&uStack_2c);
            if (uVar2 != 0) goto _L0;
            puVar6 = puVar6 + uStack_2c;
            uVar5 = uVar5 - (uStack_2c & 0xffff) & 0xffff;
            uVar4 = uVar2;
          }
          else {
            uVar4 = auStack_24[0];
            switch(auStack_24[0]) {
            case 1:
              break;
            case 2:
              uVar4 = 0xc;
              break;
            case 3:
              uVar4 = 7;
              break;
            case 4:
              uVar4 = 0xd;
              break;
            default:
              uVar4 = auStack_24[0] - 0x4000;
              if (0x10000 < auStack_24[0] - 0x4000) {
                uVar4 = 1;
              }
              break;
            case 9:
              uVar4 = uVar1;
              break;
            case 0xb:
              uVar4 = 3;
              break;
            case 0xc:
              uVar4 = 5;
              break;
            case 0xd:
            case 0x14:
              uVar4 = 0x17;
              break;
            case 0xe:
              uVar4 = 2;
              break;
            case 0x11:
              uVar4 = 0xe;
              break;
            case 0x12:
              uVar4 = 0xf;
              break;
            case 0x13:
              uVar4 = 0x18;
            }
          }
          uVar2 = uVar4;
          if (((((byte)this[0x670] & 0x20) != 0) &&
              ((*(byte *)**(undefined4 **)(this + 0x660) & 8) != 0)) &&
             (uStack_2c = spinel_datatype_unpack(puVar6,uVar5,&_LC56,&uStack_31,auStack_30),
             uVar2 = uVar1, 0 < (int)uStack_2c)) {
            ot::Mac::Frame::SetKeyId((uchar)*(undefined4 *)(this + 0x660));
            ot::Mac::Frame::SetFrameCounter(*(ulong *)(this + 0x660));
            uVar2 = uVar4;
          }
        }
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
_L0:
  *(undefined4 *)(this + 0x700) = 4;
  *(uint *)(this + 0x674) = uVar2;
  if (uVar2 != 0) {
    uVar3 = otThreadErrorToString(uVar2);
    otLogWarn(0xc,_LC2,"%s: %s","Handle transmit done failed",uVar3);
  }
  return;
}

