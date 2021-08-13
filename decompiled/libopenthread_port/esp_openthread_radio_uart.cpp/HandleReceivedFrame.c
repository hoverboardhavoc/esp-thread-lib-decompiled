/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleReceivedFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleReceivedFrame() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleReceivedFrame(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *this)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uchar *puVar4;
  byte abStack_11 [9];
  
  iVar2 = spinel_datatype_unpack
                    (*(int *)(this + 4) -
                     (*(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4) & 0xffff
                     ,&_LC40,abStack_11);
  if (((0 < iVar2) && ((char)abStack_11[0] < '\0')) && (((int)(uint)abStack_11[0] >> 4 & 3U) == 0))
  {
    if ((abStack_11[0] & 0xf) == 0) {
      HandleNotification(this,(MultiFrameBuffer *)(this + 4));
      return;
    }
    puVar4 = (uchar *)(*(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4);
    HandleResponse(this,puVar4,(short)*(undefined4 *)(this + 4) - (short)puVar4);
    iVar2 = *(int *)(this + 0x40c);
    sVar1 = (short)(this + 0x40a);
    if ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
        (iVar2 + 4) <= this + 0x40a) {
      *(undefined1 *)(iVar2 + 2) = 0;
      *(undefined1 *)(iVar2 + 3) = 0;
      iVar2 = *(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4;
      *(int *)(this + 4) = iVar2;
      *(short *)(this + 8) = sVar1 - (short)iVar2;
    }
    iVar2 = *(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4;
    *(int *)(this + 4) = iVar2;
    *(short *)(this + 8) = sVar1 - (short)iVar2;
    return;
  }
  iVar2 = *(int *)(this + 0x40c);
  sVar1 = (short)(this + 0x40a);
  if ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
      (iVar2 + 4) <= this + 0x40a) {
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined1 *)(iVar2 + 3) = 0;
    iVar2 = *(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4;
    *(int *)(this + 4) = iVar2;
    *(short *)(this + 8) = sVar1 - (short)iVar2;
  }
  iVar2 = *(int *)(this + 0x40c) + *(ushort *)(*(int *)(this + 0x40c) + 2) + 4;
  *(int *)(this + 4) = iVar2;
  *(short *)(this + 8) = sVar1 - (short)iVar2;
  uVar3 = otThreadErrorToString(6);
  otLogWarn(0xc,_LC3,"Error handling hdlc frame: %s",uVar3);
  return;
}

