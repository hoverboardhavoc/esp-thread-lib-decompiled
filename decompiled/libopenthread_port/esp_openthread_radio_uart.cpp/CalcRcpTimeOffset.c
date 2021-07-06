/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  uint extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 auStack_30 [8];
  uint uStack_28;
  int iStack_24;
  
  uStack_28 = 0;
  iStack_24 = 0;
  if ((*(uint *)(this + 0x704) >> 3 & 1) != 0) {
    uVar1 = otPlatTimeGet();
    if ((extraout_a1 < *(uint *)(this + 0x71c)) ||
       ((*(uint *)(this + 0x71c) == extraout_a1 && (uVar1 < *(uint *)(this + 0x718))))) {
      iVar7 = 0;
      goto _L0;
    }
  }
  pcVar2 = (char *)spinel_datatype_pack(auStack_30,8,&_LC35,uStack_28,iStack_24);
  if (pcVar2 + -1 < (char *)0x8) {
    uVar1 = otPlatTimeGet();
    iVar7 = GetWithParam((ulong)this,(uchar *)0x802,(uint)auStack_30,pcVar2);
    uVar3 = otPlatTimeGet();
    if (iVar7 == 0) {
      uVar5 = uVar3 >> 1 | extraout_a1_01 << 0x1f;
      uVar1 = (uVar1 >> 1 | extraout_a1_00 << 0x1f) + uVar5;
      uVar6 = uStack_28 - uVar1;
      *(uint *)(this + 0x720) = uVar6;
      *(uint *)(this + 0x724) =
           (iStack_24 - ((uint)(uVar1 < uVar5) + (extraout_a1_00 >> 1) + (extraout_a1_01 >> 1))) -
           (uint)(uStack_28 < uVar6);
      this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x704] | 8);
      *(uint *)(this + 0x718) = uVar3 + 60000000;
      *(uint *)(this + 0x71c) = (uVar3 + 60000000 < uVar3) + extraout_a1_01;
    }
    else {
      *(uint *)(this + 0x718) = uVar3;
      *(uint *)(this + 0x71c) = extraout_a1_01;
    }
  }
  else {
    iVar7 = 3;
  }
_L0:
  if (iVar7 != 0) {
    uVar4 = otThreadErrorToString(iVar7);
    otLogWarn(0xc,_LC2,"%s: %s","Error calculating RCP time offset: %s",uVar4);
  }
  return;
}

