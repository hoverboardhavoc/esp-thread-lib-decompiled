/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
    if ((extraout_a1_01 < *(uint *)(this + 0x71c)) ||
       ((*(uint *)(this + 0x71c) == extraout_a1_01 && (uVar3 < *(uint *)(this + 0x718))))) {
      iVar6 = 0;
      goto _L0;
    }
  }
  pcVar2 = (char *)spinel_datatype_pack(auStack_28,8,&_LC30,0,0);
  iVar6 = 3;
  if (pcVar2 + -1 < (char *)0x8) {
    uVar3 = otPlatTimeGet();
    iVar6 = GetWithParam((ulong)this,(uchar *)0x802,(uint)auStack_28,pcVar2);
    uVar4 = otPlatTimeGet();
    if (iVar6 == 0) {
      uVar5 = uVar4 >> 1 | extraout_a1_00 << 0x1f;
      uVar3 = (uVar3 >> 1 | extraout_a1 << 0x1f) + uVar5;
      iVar1 = -uVar3;
      *(int *)(this + 0x720) = iVar1;
      this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x704] | 8);
      *(uint *)(this + 0x724) =
           -(uint)(iVar1 != 0) -
           ((uint)(uVar3 < uVar5) + (extraout_a1 >> 1) + (extraout_a1_00 >> 1));
      *(uint *)(this + 0x718) = uVar4 + 60000000;
      *(uint *)(this + 0x71c) = (uVar4 + 60000000 < uVar4) + extraout_a1_00;
    }
    else {
      *(uint *)(this + 0x718) = uVar4;
      *(uint *)(this + 0x71c) = extraout_a1_00;
    }
  }
_L0:
  LogIfFail("Error calculating RCP time offset: %s",iVar6);
  return;
}

