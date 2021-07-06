/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  byte bStack_21;
  uint uStack_20;
  uchar *puStack_1c;
  undefined4 uStack_18;
  ulong auStack_14 [2];
  
  uStack_18 = 0;
  puStack_1c = (uchar *)0x0;
  iVar2 = spinel_datatype_unpack
                    (*(int *)param_1 -
                     (*(int *)(param_1 + 0x408) + *(ushort *)(*(int *)(param_1 + 0x408) + 2) + 4) &
                     0xffff,&_LC58,&bStack_21,&uStack_20,auStack_14,&puStack_1c,&uStack_18);
  if (iVar2 < 1) {
    iVar2 = 6;
  }
  else if ((bStack_21 & 0xf) == 0) {
    if (uStack_20 == 6) {
      if ((auStack_14[0] == 0x71) || (auStack_14[0] == 0x39)) {
        puVar4 = *(undefined1 **)(param_1 + 0x408);
        iVar2 = (uint)*(ushort *)(puVar4 + 2) +
                (*(int *)param_1 - (int)(puVar4 + *(ushort *)(puVar4 + 2) + 4) & 0xffffU);
        *puVar4 = (char)((uint)(iVar2 * 0x10000) >> 0x10);
        puVar4[1] = (char)((uint)iVar2 >> 8);
        iVar2 = *(int *)param_1;
        *(int *)(param_1 + 0x408) = iVar2;
        sVar1 = (short)(param_1 + 0x406);
        if ((MultiFrameBuffer *)(iVar2 + 4) <= param_1 + 0x406) {
          *(undefined1 *)(iVar2 + 2) = 0;
          *(undefined1 *)(iVar2 + 3) = 0;
          iVar2 = *(int *)(param_1 + 0x408) + *(ushort *)(*(int *)(param_1 + 0x408) + 2) + 4;
          *(int *)param_1 = iVar2;
          *(short *)(param_1 + 4) = sVar1 - (short)iVar2;
        }
        iVar2 = *(int *)(param_1 + 0x408) + *(ushort *)(*(int *)(param_1 + 0x408) + 2) + 4;
        *(int *)param_1 = iVar2;
        *(short *)(param_1 + 4) = sVar1 - (short)iVar2;
        iVar2 = 0;
        goto _L0;
      }
      HandleValueIs(this,auStack_14[0],puStack_1c,(ushort)uStack_18);
      iVar2 = 0;
    }
    else if (uStack_20 < 6) {
      iVar2 = 6;
    }
    else if (uStack_20 < 9) {
      otLogInfo(0xc,_LC2,"Ignored command %d");
      iVar2 = 0;
    }
    else {
      iVar2 = 6;
    }
  }
  else {
    iVar2 = 6;
  }
  iVar5 = *(int *)(param_1 + 0x408);
  sVar1 = (short)(param_1 + 0x406);
  if ((MultiFrameBuffer *)(iVar5 + 4) <= param_1 + 0x406) {
    *(undefined1 *)(iVar5 + 2) = 0;
    *(undefined1 *)(iVar5 + 3) = 0;
    iVar5 = *(int *)(param_1 + 0x408) + *(ushort *)(*(int *)(param_1 + 0x408) + 2) + 4;
    *(int *)param_1 = iVar5;
    *(short *)(param_1 + 4) = sVar1 - (short)iVar5;
  }
  iVar5 = *(int *)(param_1 + 0x408) + *(ushort *)(*(int *)(param_1 + 0x408) + 2) + 4;
  *(int *)param_1 = iVar5;
  *(short *)(param_1 + 4) = sVar1 - (short)iVar5;
_L0:
  if (iVar2 != 0) {
    uVar3 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing notification",uVar3);
  }
  return;
}

