/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  iVar4 = spinel_datatype_unpack(uVar2,uVar3,&_LC34,&bStack_11);
  if (((0 < iVar4) && ((char)bStack_11 < '\0')) && (((int)(uint)bStack_11 >> 4 & 3U) == 0)) {
    if ((bStack_11 & 0xf) == 0) {
      HandleNotification(this,(MultiFrameBuffer *)this_00);
      return;
    }
    puVar5 = (uchar *)Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                                (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
    uVar1 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
    HandleResponse(this,puVar5,uVar1);
    Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
    return;
  }
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
  uVar2 = otThreadErrorToString(6);
  otLogWarn(0xc,"-PLAT----: ","Error handling hdlc frame: %s",uVar2);
  return;
}

