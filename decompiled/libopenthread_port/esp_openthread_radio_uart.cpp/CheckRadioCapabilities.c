/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckRadioCapabilities
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::CheckRadioCapabilities() */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
CheckRadioCapabilities
          (RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this
          )

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
  aRStack_14 [12];
  
  iVar1 = Get((ulong)this,(char *)0x120b,&_LC10,aRStack_14);
  if ((iVar1 == 0) && (this[0x670] = aRStack_14[0], ((byte)aRStack_14[0] & 0x6d) != 0x6d)) {
    bVar3 = ~(byte)aRStack_14[0];
    pcVar7 = "";
    iVar1 = 0x71c;
    if ((bVar3 & 1) != 0) {
      iVar1 = 0x70c;
    }
    pcVar4 = pcVar7;
    if ((bVar3 & 4) != 0) {
      pcVar4 = "tx-retries ";
    }
    pcVar5 = pcVar7;
    if ((bVar3 & 8) != 0) {
      pcVar5 = "CSMA-backoff ";
    }
    pcVar6 = pcVar7;
    if ((bVar3 & 0x20) != 0) {
      pcVar6 = "tx-security ";
    }
    if ((bVar3 & 0x40) != 0) {
      pcVar7 = "tx-timing ";
    }
    _otLogCrit(0xc,"RCP is missing required capabilities: %s%s%s%s%s",&DAT_00013000 + iVar1,pcVar4,
               pcVar5,pcVar6,pcVar7);
    uVar2 = otExitCodeToString(3);
    _otLogCrit(0xc,"%s() at %s:%d: %s","CheckRadioCapabilities",
               "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x180,
               uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

