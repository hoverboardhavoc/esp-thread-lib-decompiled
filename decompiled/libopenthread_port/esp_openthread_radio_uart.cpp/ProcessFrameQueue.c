/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__src;
  uint uVar2;
  uint uVar3;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__dest;
  int iVar4;
  
  uVar2 = 0;
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
      __src = pRVar1 + uVar2;
    }
    if (__src == *(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   **)(this + 0x40c)) {
      uVar2 = (int)__src - (int)__dest;
      if ((uVar2 & 0xffff) != 0) {
        iVar4 = *(int *)(this + 4);
        memmove(__dest,__src,iVar4 - (int)__src & 0xffff);
        *(uint *)(this + 4) = iVar4 - (uVar2 & 0xffff);
        *(uint *)(this + 0x40c) = *(int *)(this + 0x40c) - (uVar2 & 0xffff);
        *(short *)(this + 8) = (short)(uVar2 * 0x10000 >> 0x10) + *(short *)(this + 8);
      }
      return;
    }
    uVar3 = (uint)*(ushort *)__src - (uint)*(ushort *)(__src + 2);
    uVar2 = uVar3 & 0xffff;
    pRVar1 = __src + *(ushort *)(__src + 2) + 4;
    HandleNotification(this,(uchar *)pRVar1,(ushort)uVar3);
  } while( true );
}

