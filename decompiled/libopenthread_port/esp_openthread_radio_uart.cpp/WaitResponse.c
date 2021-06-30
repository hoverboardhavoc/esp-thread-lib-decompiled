/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> WaitResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   WaitResponse(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
WaitResponse(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
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
      HandleRcpTimeout(this);
_L0:
      HandleRcpTimeout(this);
      goto _L0;
    }
    iVar2 = esp::openthread::UartSpinelInterface::WaitForFrame(uVar5);
    if (iVar2 != 0) goto _L0;
  } while ((this->mWaitingTid != '\0') || ((*(uint *)&this->field_0x704 >> 1 & 1) == 0));
  if (this->mError != OT_ERROR_NONE) {
_L0:
    uVar3 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error waiting response",uVar3);
  }
  this->mWaitingKey = 0;
  return this->mError;
}

