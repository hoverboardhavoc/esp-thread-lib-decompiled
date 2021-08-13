/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> WaitResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::WaitResponse() */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
WaitResponse(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
             *this)

{
  uint uVar1;
  uint extraout_a0;
  int iVar2;
  undefined4 uVar3;
  int extraout_a1;
  uint extraout_a1_00;
  uint uVar4;
  ulonglong uVar5;
  
  uVar1 = otPlatTimeGet();
  uVar4 = (uint)(uVar1 + 2000000 < uVar1) + extraout_a1;
  do {
    uVar5 = otPlatTimeGet();
    if ((uVar4 <= extraout_a1_00) && ((uVar4 != extraout_a1_00 || (uVar1 + 2000000 <= extraout_a0)))
       ) {
      HandleRcpTimeout();
_L0:
      HandleRcpTimeout();
      goto _L0;
    }
    iVar2 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar5);
    if (iVar2 != 0) goto _L0;
  } while ((this[0x464] !=
            (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0
           ) || ((*(uint *)(this + 0x704) >> 1 & 1) == 0));
  if (*(int *)(this + 0x478) != 0) {
_L0:
    uVar3 = otThreadErrorToString();
    otLogWarn(0xc,_LC3,"%s: %s","Error waiting response",uVar3);
  }
  *(undefined4 *)(this + 0x468) = 0;
  return *(undefined4 *)(this + 0x478);
}

