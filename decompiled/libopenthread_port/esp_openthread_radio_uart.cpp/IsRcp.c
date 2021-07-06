/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> IsRcp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::IsRcp(bool&) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
IsRcp(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
     bool *param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iStack_8c;
  int iStack_88;
  undefined1 auStack_84 [108];
  
  iStack_88 = 100;
  *param_1 = false;
  iVar3 = Get((ulong)this,(char *)0x5,&_LC13,auStack_84,&iStack_88);
  if (iVar3 != 0) {
    iVar3 = Get((ulong)this,(char *)0x5,&_LC13,auStack_84,&iStack_88);
    if (iVar3 == 7) {
      uVar4 = 2;
    }
    else {
      uVar4 = 1;
    }
    uVar4 = otExitCodeToString(uVar4);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x137,
              uVar4);
    iVar3 = Get((ulong)this,(char *)0x5,&_LC13,auStack_84,&iStack_88);
    if (iVar3 == 7) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar3);
  }
  iVar3 = 0;
  bVar1 = false;
  puVar2 = auStack_84;
  for (; iStack_88 != 0; iStack_88 = iStack_88 - iVar5) {
    iVar5 = spinel_datatype_unpack(puVar2,&_LC14,&iStack_8c);
    if (iVar5 < 1) {
      uVar4 = otExitCodeToString(3);
      otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x13f,
                uVar4);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
    if (iStack_8c == 0x201) {
      bVar1 = true;
    }
    if (iStack_8c == 0x22) {
      iVar3 = 1;
    }
    if (iStack_8c == 0x206) {
      this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     )((byte)this[0x704] | 4);
    }
    if (iStack_8c == 0x40) {
      *param_1 = true;
    }
    puVar2 = puVar2 + iVar5;
  }
  if ((!bVar1) && (iVar3 != 0)) {
    otLogCrit(0xc,_LC2,"RCP capability list does not include support for radio/raw mode");
    uVar4 = otExitCodeToString(3);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x15c,
              uVar4);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return iVar3;
}

