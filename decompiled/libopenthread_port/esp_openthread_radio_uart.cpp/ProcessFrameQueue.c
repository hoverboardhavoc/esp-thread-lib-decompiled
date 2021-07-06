/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  uint uVar2;
  void *__src;
  int iVar3;
  
  uVar2 = 0;
  pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           0x0;
  while( true ) {
    if ((pRVar1 != (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)0x0) && ((pRVar1 < this + 10 || (this + 0x40a <= pRVar1)))) {
      otPlatAssertFail("IDF/components/openthread/openthread/src/lib/hdlc/hdlc.hpp",0x171);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (pRVar1 == (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *)0x0) {
      pRVar1 = this + 10;
    }
    else {
      pRVar1 = pRVar1 + uVar2;
    }
    if (pRVar1 == *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    **)(this + 0x40c)) {
      uVar2 = 0;
      pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)0x0;
      iVar3 = 0x17;
    }
    else {
      uVar2 = (uint)*(ushort *)pRVar1 - (uint)*(ushort *)(pRVar1 + 2) & 0xffff;
      pRVar1 = pRVar1 + *(ushort *)(pRVar1 + 2) + 4;
      iVar3 = 0;
    }
    if (iVar3 != 0) break;
    HandleNotification(this,(uchar *)pRVar1,(ushort)uVar2);
  }
  __src = *(void **)(this + 0x40c);
  uVar2 = (int)__src - (int)(this + 10);
  if ((uVar2 & 0xffff) != 0) {
    iVar3 = *(int *)(this + 4);
    memmove(this + 10,__src,iVar3 - (int)__src & 0xffff);
    *(uint *)(this + 4) = iVar3 + -(uVar2 & 0xffff);
    *(uint *)(this + 0x40c) = -(uVar2 & 0xffff) + *(int *)(this + 0x40c);
    *(short *)(this + 8) = (short)(uVar2 * 0x10000 >> 0x10) + *(short *)(this + 8);
  }
  return;
}

