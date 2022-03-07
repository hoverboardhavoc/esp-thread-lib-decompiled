/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
  aRStack_14 [12];
  
  iVar2 = Get((ulong)this,(char *)0x120b,&_LC12,aRStack_14);
  if ((iVar2 == 0) && (this[0x670] = aRStack_14[0], ((byte)aRStack_14[0] & 0x6d) != 0x6d)) {
    bVar1 = ~(byte)aRStack_14[0];
    pcVar7 = "";
    iVar2 = -0x7d8;
    if ((bVar1 & 1) != 0) {
      iVar2 = -0x7e8;
    }
    pcVar4 = pcVar7;
    if ((bVar1 & 4) != 0) {
      pcVar4 = "tx-retries ";
    }
    pcVar5 = pcVar7;
    if ((bVar1 & 8) != 0) {
      pcVar5 = "CSMA-backoff ";
    }
    pcVar6 = pcVar7;
    if ((bVar1 & 0x20) != 0) {
      pcVar6 = "tx-security ";
    }
    if ((bVar1 & 0x40) != 0) {
      pcVar7 = "tx-timing ";
    }
    otLogCritPlat("RCP is missing required capabilities: %s%s%s%s%s",
                  ot::Spinel::Decoder::Decoder + iVar2,pcVar4,pcVar5,pcVar6,pcVar7);
    uVar3 = otExitCodeToString(3);
    otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x187
                  ,uVar3);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

