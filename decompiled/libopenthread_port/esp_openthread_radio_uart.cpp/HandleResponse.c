/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> RVar1;
  int iVar2;
  undefined2 in_register_00002032;
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
  iVar2 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&_LC53,&bStack_21,auStack_14,
                     &uStack_20,&puStack_1c,&uStack_18);
  uVar3 = 6;
  if ((0 < iVar2) && (auStack_14[0] - 6 < 3)) {
    if (this[0x464] ==
        (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
        (bStack_21 & 0xf)) {
      HandleWaitingResponse(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
      RVar1 = this[0x464];
      this[0x464] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      *(ushort *)(this + 0x460) = ~(ushort)(1 << ((byte)RVar1 & 0x1f)) & *(ushort *)(this + 0x460);
    }
    else {
      if (this[0x463] !=
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
          (bStack_21 & 0xf)) {
        otLogWarn(0xc,"-PLAT----: ","Unexpected Spinel transaction message: %u");
        uVar3 = 2;
        goto _L0;
      }
      if (*(int *)(this + 0x700) == 3) {
        HandleTransmitDone(this,auStack_14[0],uStack_20,puStack_1c,(ushort)uStack_18);
      }
      RVar1 = this[0x463];
      this[0x463] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      *(ushort *)(this + 0x460) = ~(ushort)(1 << ((byte)RVar1 & 0x1f)) & *(ushort *)(this + 0x460);
    }
    uVar3 = 0;
  }
_L0:
  LogIfFail("Error processing response",uVar3);
  return;
}

