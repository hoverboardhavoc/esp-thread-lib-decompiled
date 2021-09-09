/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  uint uVar2;
  uint extraout_a0;
  int iVar3;
  int extraout_a1;
  uint extraout_a1_00;
  ulonglong uVar4;
  
  uVar2 = otPlatTimeGet();
  uVar1 = (uint)(uVar2 + 2000000 < uVar2) + extraout_a1;
  do {
    uVar4 = otPlatTimeGet();
    if (extraout_a1_00 < uVar1) goto _L0;
    if ((uVar1 == extraout_a1_00) && (extraout_a0 < uVar2 + 2000000)) goto _L0;
    do {
      uVar4 = HandleRcpTimeout();
_L0:
      iVar3 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar4);
    } while (iVar3 != 0);
  } while ((this[0x464] !=
            (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0
           ) || ((*(uint *)(this + 0x704) >> 1 & 1) == 0));
  LogIfFail("Error waiting response",*(undefined4 *)(this + 0x478));
  *(undefined4 *)(this + 0x468) = 0;
  return *(undefined4 *)(this + 0x478);
}

