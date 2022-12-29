/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
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
  
  iVar1 = Get((ulong)this,(char *)0x120b,&_LC30,aRStack_14);
  if ((iVar1 == 0) && (this[0x670] = aRStack_14[0], ((byte)aRStack_14[0] & 0x6d) != 0x6d)) {
    bVar6 = ~(byte)aRStack_14[0];
    pcVar7 = "";
    iVar1 = 0x38c;
    if ((bVar6 & 1) != 0) {
      iVar1 = 0x37c;
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
    otLogCritPlat("RCP is missing required capabilities: %s%s%s%s%s",
                  "Spinel version mismatch - Posix:%d.%d, RCP:%d.%d" + iVar1 + 8,pcVar3,pcVar4,
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

