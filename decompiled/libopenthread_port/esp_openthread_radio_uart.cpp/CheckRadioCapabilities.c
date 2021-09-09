/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  char *pcVar8;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
  aRStack_14 [12];
  
  iVar1 = Get((ulong)this,(char *)0x120b,&_LC11,aRStack_14);
  if ((iVar1 == 0) && (this[0x670] = aRStack_14[0], ((byte)aRStack_14[0] & 0x6d) != 0x6d)) {
    bVar3 = ~(byte)aRStack_14[0];
    pcVar8 = "";
    pcVar4 = "";
    if ((bVar3 & 1) != 0) {
      pcVar4 = "ack-timeout ";
    }
    pcVar5 = pcVar8;
    if ((bVar3 & 4) != 0) {
      pcVar5 = "tx-retries ";
    }
    pcVar6 = pcVar8;
    if ((bVar3 & 8) != 0) {
      pcVar6 = "CSMA-backoff ";
    }
    pcVar7 = pcVar8;
    if ((bVar3 & 0x20) != 0) {
      pcVar7 = "tx-security ";
    }
    if ((bVar3 & 0x40) != 0) {
      pcVar8 = "tx-timing ";
    }
    otLogCrit(0xc,"-PLAT----: ","RCP is missing required capabilities: %s%s%s%s%s",pcVar4,pcVar5,
              pcVar6,pcVar7,pcVar8);
    uVar2 = otExitCodeToString(3);
    otLogCrit(0xc,"-PLAT----: ","%s() at %s:%d: %s","CheckRadioCapabilities",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x180,
              uVar2);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return;
}

