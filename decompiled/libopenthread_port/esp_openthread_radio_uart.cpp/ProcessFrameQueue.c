/*
 * Last changed at upstream commit 84ba294781572ce5fbba05e95b6ebb22f3981d93
 * https://github.com/espressif/esp-thread-lib/commit/84ba294781572ce5fbba05e95b6ebb22f3981d93
 * Upstream date: 2021-11-05 16:42:38 +0800
 * Upstream subject: cli: add linenoise probing(1c286a5)
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
  int iVar3;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__src;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *__dest;
  undefined4 uVar4;
  byte bStack_41;
  ulong uStack_40;
  undefined4 uStack_3c;
  uchar *puStack_38;
  int local_34 [4];
  
  uVar2 = 0;
  pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           0x0;
  __dest = this + 10;
  do {
    __src = __dest;
    if (pRVar1 != (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *)0x0) {
      if ((pRVar1 < __dest) || (this + 0x40a <= pRVar1)) {
        otPlatAssertFail("/IDF/components/openthread/openthread/src/lib/hdlc/hdlc.hpp",0x171);
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
        iVar3 = *(int *)(this + 4);
        memmove(__dest,__src,iVar3 - (int)__src & 0xffff);
        *(uint *)(this + 4) = iVar3 + -(uVar2 & 0xffff);
        *(uint *)(this + 0x40c) = -(uVar2 & 0xffff) + *(int *)(this + 0x40c);
        *(short *)(this + 8) = (short)(uVar2 * 0x10000 >> 0x10) + *(short *)(this + 8);
      }
      return;
    }
    pRVar1 = __src + *(ushort *)(__src + 2) + 4;
    uVar2 = (uint)*(ushort *)__src - (uint)*(ushort *)(__src + 2) & 0xffff;
    uStack_3c = 0;
    puStack_38 = (uchar *)0x0;
    iVar3 = spinel_datatype_unpack
                      (pRVar1,uVar2,&_LC55,&bStack_41,local_34,&uStack_40,&puStack_38,&uStack_3c);
    uVar4 = 6;
    if (((0 < iVar3) && ((bStack_41 & 0xf) == 0)) && (uVar4 = 0, local_34[0] == 6)) {
      HandleValueIs(this,uStack_40,puStack_38,(ushort)uStack_3c);
    }
    LogIfFail("Error processing saved notification",uVar4);
  } while( true );
}

