/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iStack_9c;
  int iStack_98;
  undefined1 auStack_94 [100];
  
  *param_1 = false;
  iStack_9c = 100;
  iVar3 = Get((ulong)this,(char *)0x5,&_LC50,auStack_94,&iStack_9c);
  if (iVar3 == 0) {
    iVar3 = 0;
    bVar1 = false;
    puVar2 = auStack_94;
    for (; iStack_9c != 0; iStack_9c = iStack_9c - iVar4) {
      iVar4 = spinel_datatype_unpack(puVar2,&_LC31,&iStack_98);
      if (iVar4 < 1) {
        uVar5 = otExitCodeToString(3);
        uVar6 = 0x14a;
        goto _L690;
      }
      if (iStack_98 == 0x201) {
        bVar1 = true;
      }
      else if (iStack_98 == 0x22) {
        iVar3 = 1;
      }
      else if (iStack_98 == 0x206) {
        this[0x704] = (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       )((byte)this[0x704] | 4);
      }
      else if (iStack_98 == 0x40) {
        *param_1 = true;
      }
      puVar2 = puVar2 + iVar4;
    }
    if ((bVar1) || (iVar3 == 0)) {
      return iVar3;
    }
    otLogCritPlat("RCP capability list does not include support for radio/raw mode");
    uVar5 = otExitCodeToString(3);
    uVar6 = 0x167;
_L690:
    otLogCritPlat("%s() at %s:%d: %s","IsRcp",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",uVar6
                  ,uVar5);
    iVar3 = 3;
  }
  else {
    iVar3 = Get((ulong)this,(char *)0x5,&_LC50,auStack_94,&iStack_9c);
    uVar6 = 2;
    if (iVar3 != 7) {
      uVar6 = 1;
    }
    uVar6 = otExitCodeToString(uVar6);
    otLogCritPlat("%s() at %s:%d: %s","IsRcp",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x142
                  ,uVar6);
    iVar4 = Get((ulong)this,(char *)0x5,&_LC50,auStack_94,&iStack_9c);
    iVar3 = 2;
    if (iVar4 != 7) {
      iVar3 = 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  exit(iVar3);
}

