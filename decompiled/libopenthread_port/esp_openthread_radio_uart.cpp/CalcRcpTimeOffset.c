/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CalcRcpTimeOffset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::CalcRcpTimeOffset() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
CalcRcpTimeOffset(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *this)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint uVar5;
  int iVar6;
  undefined1 auStack_28 [16];
  
  if ((*(uint *)(this + 0x704) >> 3 & 1) != 0) {
    uVar3 = otPlatTimeGet();
    if ((extraout_a1_01 < *(uint *)(this + 0x7c4)) ||
       ((*(uint *)(this + 0x7c4) == extraout_a1_01 && (uVar3 < *(uint *)(this + 0x7c0))))) {
      iVar6 = 0;
      goto _L0;
    }
  }
  otLogDebgPlat(0x128b8);
  pcVar2 = (char *)spinel_datatype_pack(auStack_28,8,&_LC111,0,0);
  iVar6 = 3;
  if (pcVar2 + -1 < (char *)0x8) {
    uVar3 = otPlatTimeGet();
    iVar6 = GetWithParam((ulong)this,(uchar *)0x802,(uint)auStack_28,pcVar2);
    uVar4 = otPlatTimeGet();
    if (iVar6 == 0) {
      uVar5 = uVar4 >> 1 | extraout_a1_00 << 0x1f;
      uVar3 = (uVar3 >> 1 | extraout_a1 << 0x1f) + uVar5;
      iVar1 = -uVar3;
      *(int *)(this + 0x7c8) = iVar1;
      *(uint *)(this + 0x7cc) =
           -(uint)(iVar1 != 0) -
           ((uint)(uVar3 < uVar5) + (extraout_a1_00 >> 1) + (extraout_a1 >> 1));
      this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x704] | 8);
      *(uint *)(this + 0x7c0) = uVar4 + 60000000;
      *(uint *)(this + 0x7c4) = (uVar4 + 60000000 < uVar4) + extraout_a1_00;
    }
    else {
      *(uint *)(this + 0x7c0) = uVar4;
      *(uint *)(this + 0x7c4) = extraout_a1_00;
    }
  }
_L0:
  LogIfFail("Error calculating RCP time offset: %s",iVar6);
  return;
}

