/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  undefined4 uVar2;
  undefined2 in_register_00002032;
  uint uStack_24;
  byte local_1d;
  undefined4 uStack_1c;
  uchar *puStack_18;
  ulong auStack_14 [3];
  
  puStack_18 = (uchar *)0x0;
  uStack_1c = 0;
  local_1d = 0;
  uStack_24 = 0;
  iVar1 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&_LC58,&local_1d,&uStack_24,
                     auStack_14,&puStack_18,&uStack_1c);
  if (iVar1 < 1) {
    iVar1 = 6;
  }
  else if (uStack_24 < 6) {
    iVar1 = 6;
  }
  else if (uStack_24 < 9) {
    if (this[0x464] ==
        (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
        (local_1d & 0xf)) {
      HandleWaitingResponse(this,uStack_24,auStack_14[0],puStack_18,(ushort)uStack_1c);
      *(ushort *)(this + 0x460) =
           ~(ushort)(1 << ((byte)this[0x464] & 0x1f)) & *(ushort *)(this + 0x460);
      this[0x464] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      iVar1 = 0;
    }
    else if (this[0x463] ==
             (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)
             (local_1d & 0xf)) {
      if (*(int *)(this + 0x700) == 3) {
        HandleTransmitDone(this,uStack_24,auStack_14[0],puStack_18,(ushort)uStack_1c);
      }
      *(ushort *)(this + 0x460) =
           ~(ushort)(1 << ((byte)this[0x463] & 0x1f)) & *(ushort *)(this + 0x460);
      this[0x463] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )0x0;
      iVar1 = 0;
    }
    else {
      otLogWarn(0xc,_LC2,"Unexpected Spinel transaction message: %u");
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 6;
  }
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing response",uVar2);
  }
  return;
}

