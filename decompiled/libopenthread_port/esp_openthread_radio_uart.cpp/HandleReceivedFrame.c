/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  uchar *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  byte bStack_11;
  
  this_00 = (MultiFrameBuffer<(unsigned_short)1024> *)(this + 4);
  puVar2 = (uchar *)Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                              (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
  uVar1 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
  LogSpinelFrame(this,puVar2,uVar1,false);
  uVar3 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                    (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
  uVar4 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
  iVar5 = spinel_datatype_unpack(uVar3,uVar4,&_LC36,&bStack_11);
  if (0 < iVar5) {
    if (((char)bStack_11 < '\0') && (((int)(uint)bStack_11 >> 4 & 3U) == 0)) {
      if ((bStack_11 & 0xf) == 0) {
        HandleNotification(this,(MultiFrameBuffer *)this_00);
      }
      else {
        puVar2 = (uchar *)Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                                    (*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x40c));
        uVar1 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength(this_00);
        HandleResponse(this,puVar2,uVar1);
        Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
      }
      uVar3 = 0;
      goto _L0;
    }
  }
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame(this_00);
  uVar3 = otThreadErrorToString(6);
  otLogWarnPlat("Error handling hdlc frame: %s",uVar3);
  uVar3 = 6;
_L0:
  UpdateParseErrorCount(this,uVar3);
  return;
}

