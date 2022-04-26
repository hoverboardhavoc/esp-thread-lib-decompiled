/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  int iVar1;
  undefined2 in_register_00002032;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar2;
  undefined4 uVar3;
  byte bStack_21;
  ulong uStack_20;
  uchar *puStack_1c;
  undefined4 uStack_18;
  ulong auStack_14 [3];
  
  puStack_1c = (uchar *)0x0;
  uStack_18 = 0;
  bStack_21 = 0;
  auStack_14[0] = 0;
  iVar1 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&_LC55,&bStack_21,auStack_14,
                     &uStack_20,&puStack_1c,&uStack_18);
  uVar3 = 6;
  if (0 < iVar1) {
    if (auStack_14[0] - 6 < 3) {
      RVar2 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
              (bStack_21 & 0xf);
      if (this[0x464] == RVar2) {
        HandleWaitingResponse(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
        RVar2 = this[0x464];
        this[0x464] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       )0x0;
        *(ushort *)(this + 0x460) = ~(ushort)(1 << ((byte)RVar2 & 0x1f)) & *(ushort *)(this + 0x460)
        ;
      }
      else {
        if (this[0x463] != RVar2) {
          otLogWarnPlat("Unexpected Spinel transaction message: %u",RVar2);
          uVar3 = 2;
          goto _L0;
        }
        if (*(int *)(this + 0x700) == 3) {
          HandleTransmitDone(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
        }
        RVar2 = this[0x463];
        this[0x463] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       )0x0;
        *(ushort *)(this + 0x460) = ~(ushort)(1 << ((byte)RVar2 & 0x1f)) & *(ushort *)(this + 0x460)
        ;
      }
      uVar3 = 0;
    }
  }
_L0:
  LogIfFail("Error processing response",uVar3);
  return;
}

