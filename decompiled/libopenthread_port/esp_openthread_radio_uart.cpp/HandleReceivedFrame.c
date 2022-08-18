/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  MultiFrameBuffer<(unsigned_short)1024> *this_00;
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uchar *puVar5;
  byte bStack_11;
  
  this_00 = (MultiFrameBuffer<(unsigned_short)1024> *)(this + 4);
  uVar2 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                    (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
  uVar3 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
  iVar4 = spinel_datatype_unpack(uVar2,uVar3,&_LC10,&bStack_11);
  if (0 < iVar4) {
    if (((char)bStack_11 < '\0') && (((int)(uint)bStack_11 >> 4 & 3U) == 0)) {
      if ((bStack_11 & 0xf) == 0) {
        HandleNotification(this,(MultiFrameBuffer *)this_00);
      }
      else {
        puVar5 = (uchar *)Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                                    (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
        uVar1 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
        HandleResponse(this,puVar5,uVar1);
        Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
      }
      uVar2 = 0;
      goto _L0;
    }
  }
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
  uVar2 = otThreadErrorToString(6);
  otLogWarnPlat("Error handling hdlc frame: %s",uVar2);
  uVar2 = 6;
_L0:
  UpdateParseErrorCount(this,uVar2);
  return;
}

