/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> ProcessRadioStateMachine
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::ProcessRadioStateMachine() */

RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> * __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
ProcessRadioStateMachine
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *pRVar1;
  int iVar2;
  uint extraout_a1;
  char cVar3;
  
  if (*(int *)(this + 0x700) == 4) {
    *(undefined4 *)(this + 0x700) = 2;
    *(undefined4 *)(this + 0x710) = 0xffffffff;
    *(undefined4 *)(this + 0x714) = 0xffffffff;
    if (*(short *)(this + 0x644) == 0) {
      pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)0x0;
    }
    else {
      pRVar1 = this + 0x640;
    }
    pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             TransmitDone(this,*(undefined4 *)(this + 0x660),pRVar1,*(undefined4 *)(this + 0x674));
  }
  else {
    pRVar1 = this;
    if (*(int *)(this + 0x700) == 3) {
      pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)otPlatTimeGet();
      if ((*(uint *)(this + 0x714) <= extraout_a1) &&
         ((*(uint *)(this + 0x714) != extraout_a1 ||
          (*(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> **)
            (this + 0x710) <= pRVar1)))) {
        otLogWarn(0xc,_LC2,"radio tx timeout");
        iVar2 = HandleRcpTimeout();
        pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)(uint)*(byte *)(iVar2 + 0x462);
        if (((int)(uint)*(ushort *)(iVar2 + 0x460) >> ((uint)pRVar1 & 0x1f) & 1U) == 0) {
          if (pRVar1 < (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)0xf) {
            cVar3 = *(byte *)(iVar2 + 0x462) + 1;
          }
          else {
            cVar3 = '\x01';
          }
          *(char *)(iVar2 + 0x462) = cVar3;
          *(ushort *)(iVar2 + 0x460) =
               *(ushort *)(iVar2 + 0x460) | (ushort)(1 << ((uint)pRVar1 & 0x1f));
        }
        else {
          pRVar1 = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    *)0x0;
        }
        return pRVar1;
      }
    }
  }
  return pRVar1;
}

