/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ProcessFrameQueue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ProcessFrameQueue() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
ProcessFrameQueue(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *this)

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *pRVar1;
  int iVar2;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__src;
  uint uVar3;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__dest;
  undefined4 uVar4;
  byte bStack_41;
  ulong uStack_40;
  undefined4 uStack_3c;
  uchar *puStack_38;
  int local_34 [4];
  
  uVar3 = 0;
  pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           0x0;
  __dest = this + 10;
  do {
    __src = __dest;
    if (pRVar1 != (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *)0x0) {
      if ((pRVar1 < __dest) || (this + 0x40a <= pRVar1)) {
        otPlatAssertFail("/IDF/components/openthread/openthread/src/lib/hdlc/hdlc.hpp",0x172);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      __src = pRVar1 + uVar3;
    }
    if (__src == *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   **)(this + 0x40c)) {
      uVar3 = (int)__src - (int)__dest;
      if ((uVar3 & 0xffff) != 0) {
        iVar2 = *(int *)(this + 4);
        memmove(__dest,__src,iVar2 - (int)__src & 0xffff);
        *(uint *)(this + 4) = iVar2 - (uVar3 & 0xffff);
        *(uint *)(this + 0x40c) = *(int *)(this + 0x40c) - (uVar3 & 0xffff);
        *(short *)(this + 8) = (short)(uVar3 * 0x10000 >> 0x10) + *(short *)(this + 8);
      }
      return;
    }
    pRVar1 = __src + *(ushort *)(__src + 2) + 4;
    uVar3 = (uint)*(ushort *)__src - (uint)*(ushort *)(__src + 2) & 0xffff;
    uStack_3c = 0;
    puStack_38 = (uchar *)0x0;
    iVar2 = spinel_datatype_unpack
                      (pRVar1,uVar3,&::_L0,&bStack_41,local_34,&uStack_40,&puStack_38,&uStack_3c);
    uVar4 = 6;
    if (((0 < iVar2) && (uVar4 = 6, (bStack_41 & 0xf) == 0)) && (uVar4 = 0, local_34[0] == 6)) {
      HandleValueIs(this,uStack_40,puStack_38,(ushort)uStack_3c);
    }
    LogIfFail("Error processing saved notification",uVar4);
  } while( true );
}

