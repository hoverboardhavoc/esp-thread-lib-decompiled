/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleResponse(unsigned char const*, unsigned short) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleResponse(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
               *this,uchar *param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 in_register_00002032;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar3;
  byte bStack_21;
  ulong uStack_20;
  uchar *puStack_1c;
  undefined4 uStack_18;
  ulong auStack_14 [2];
  
  puStack_1c = (uchar *)0x0;
  uStack_18 = 0;
  bStack_21 = 0;
  auStack_14[0] = 0;
  iVar2 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&::_L0,&bStack_21,auStack_14,
                     &uStack_20,&puStack_1c,&uStack_18);
  uVar1 = 6;
  if ((0 < iVar2) && (auStack_14[0] - 6 < 3)) {
    RVar3 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
            (bStack_21 & 0xf);
    if (this[0x468] == RVar3) {
      HandleWaitingResponse(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
      RVar3 = this[0x468];
      this[0x468] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      *(ushort *)(this + 0x464) = ~(ushort)(1 << ((byte)RVar3 & 0x1f)) & *(ushort *)(this + 0x464);
    }
    else {
      if (this[0x467] != RVar3) {
        otLogWarnPlat("Unexpected Spinel transaction message: %u",RVar3);
        uVar1 = 2;
        goto _L0;
      }
      if (*(int *)(this + 0x700) == 3) {
        HandleTransmitDone(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
      }
      RVar3 = this[0x467];
      this[0x467] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      *(ushort *)(this + 0x464) = ~(ushort)(1 << ((byte)RVar3 & 0x1f)) & *(ushort *)(this + 0x464);
    }
    uVar1 = 0;
  }
_L0:
  UpdateParseErrorCount(this,uVar1);
  LogIfFail("Error processing response",uVar1);
  return;
}

