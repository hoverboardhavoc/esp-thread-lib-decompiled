/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar6;
  char *pcVar7;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
  aRStack_14 [12];
  
  iVar1 = Get((ulong)this,(char *)0x120b,&_LC31,aRStack_14);
  if ((iVar1 == 0) && (this[0x670] = aRStack_14[0], ((byte)aRStack_14[0] & 0x6d) != 0x6d)) {
    bVar6 = ~(byte)aRStack_14[0];
    pcVar7 = "";
    iVar1 = 0x300;
    if ((bVar6 & 1) != 0) {
      iVar1 = 0x2f0;
    }
    pcVar3 = pcVar7;
    if ((bVar6 & 4) != 0) {
      pcVar3 = "tx-retries ";
    }
    pcVar4 = pcVar7;
    if ((bVar6 & 8) != 0) {
      pcVar4 = "CSMA-backoff ";
    }
    pcVar5 = pcVar7;
    if ((bVar6 & 0x20) != 0) {
      pcVar5 = "tx-security ";
    }
    if ((bVar6 & 0x40) != 0) {
      pcVar7 = "tx-timing ";
    }
    otLogCritPlat("RCP is missing required capabilities: %s%s%s%s%s",iVar1 + 0x14000,pcVar3,pcVar4,
                  pcVar5,pcVar7);
    uVar2 = otExitCodeToString(3);
    otLogCritPlat("%s() at %s:%d: %s","CheckRadioCapabilities",
                  "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x18b
                  ,uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

