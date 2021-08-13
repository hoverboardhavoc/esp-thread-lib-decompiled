/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
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
  byte bVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
  aRStack_14 [12];
  
  iVar1 = Get((ulong)this,(char *)0x120b,&_LC16,aRStack_14);
  if (iVar1 == 0) {
    this[0x670] = aRStack_14[0];
    if (((byte)aRStack_14[0] & 0x6d) != 0x6d) {
      bVar5 = ~(byte)aRStack_14[0];
      if ((bVar5 & 1) == 0) {
        pcVar3 = "";
      }
      else {
        pcVar3 = "ack-timeout ";
      }
      if ((bVar5 & 4) == 0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = "tx-retries ";
      }
      if ((bVar5 & 8) == 0) {
        pcVar6 = "";
      }
      else {
        pcVar6 = "CSMA-backoff ";
      }
      if ((bVar5 & 0x20) == 0) {
        pcVar7 = "";
      }
      else {
        pcVar7 = "tx-security ";
      }
      if ((bVar5 & 0x40) == 0) {
        pcVar8 = "";
      }
      else {
        pcVar8 = "tx-timing ";
      }
      otLogCrit(0xc,_LC3,"RCP is missing required capabilities: %s%s%s%s%s",pcVar3,pcVar4,pcVar6,
                pcVar7,pcVar8);
      uVar2 = otExitCodeToString(3);
      otLogCrit(0xc,_LC3,"%s() at %s:%d: %s","CheckRadioCapabilities",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x180,
                uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return;
}

