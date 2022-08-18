/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  otLogDebgPlat("Wait response: tid=%u key=%u",this[0x468],*(undefined4 *)(this + 0x46c));
  while (((uVar4 = otPlatTimeGet(), extraout_a1_00 < uVar1 ||
          ((uVar1 == extraout_a1_00 && (extraout_a0 < uVar2 + 2000000)))) &&
         (iVar3 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar4), iVar3 == 0))) {
    if ((this[0x468] ==
         (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>)0x0)
       && ((*(uint *)(this + 0x704) >> 1 & 1) != 0)) {
      LogIfFail("Error waiting response",*(undefined4 *)(this + 0x47c));
      *(undefined4 *)(this + 0x46c) = 0;
_L0:
      return *(undefined4 *)(this + 0x47c);
    }
  }
  otLogWarnPlat("Wait for response timeout");
  *(undefined4 *)(this + 0x47c) = 0;
  *(int *)(this + 0x7e0) = *(int *)(this + 0x7e0) + 1;
  this[0x7a9] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                )((byte)this[0x7a9] | 0x40);
  goto _L0;
}

