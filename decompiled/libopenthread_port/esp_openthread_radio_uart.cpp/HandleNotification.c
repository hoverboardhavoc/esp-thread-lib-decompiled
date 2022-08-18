/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleNotification
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleNotification(ot::Hdlc::MultiFrameBuffer<(unsigned
   short)1024>&) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this,MultiFrameBuffer *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bStack_21;
  ulong uStack_20;
  undefined4 uStack_1c;
  uchar *puStack_18;
  int iStack_14;
  
  uStack_1c = 0;
  puStack_18 = (uchar *)0x0;
  uVar2 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                    (*(MultiFrameBuffer<(unsigned_short)1024> **)(param_1 + 0x408));
  uVar3 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength
                    ((MultiFrameBuffer<(unsigned_short)1024> *)param_1);
  iVar4 = spinel_datatype_unpack
                    (uVar2,uVar3,&::_L0,&bStack_21,&iStack_14,&uStack_20,&puStack_18,&uStack_1c);
  if ((iVar4 < 1) || ((bStack_21 & 0xf) != 0)) {
    uVar2 = 6;
  }
  else {
    if (iStack_14 == 6) {
      if ((uStack_20 == 0x71) || (uStack_20 == 0x39)) {
        puVar1 = *(undefined1 **)(param_1 + 0x408);
        iVar4 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetLength
                          ((MultiFrameBuffer<(unsigned_short)1024> *)param_1);
        *puVar1 = (char)(((uint)*(ushort *)(puVar1 + 2) + iVar4) * 0x10000 >> 0x10);
        puVar1[1] = (char)((uint)*(ushort *)(puVar1 + 2) + iVar4 >> 8);
        uVar2 = 0;
        *(undefined4 *)(param_1 + 0x408) = *(undefined4 *)param_1;
        Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
                  ((MultiFrameBuffer<(unsigned_short)1024> *)param_1,0);
        uVar3 = Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
                          (*(MultiFrameBuffer<(unsigned_short)1024> **)(param_1 + 0x408));
        *(undefined4 *)param_1 = uVar3;
        *(short *)(param_1 + 4) = ((short)param_1 + 0x406) - (short)uVar3;
        goto _L0;
      }
      HandleValueIs(this,uStack_20,puStack_18,(ushort)uStack_1c);
    }
    else {
      uVar2 = 6;
      if (1 < iStack_14 - 7U) goto _L0;
      otLogInfoPlat("Ignored command %d");
    }
    uVar2 = 0;
  }
_L0:
  Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame
            ((MultiFrameBuffer<(unsigned_short)1024> *)param_1);
_L0:
  UpdateParseErrorCount(this,uVar2);
  LogIfFail("Error processing notification",uVar2);
  return;
}

