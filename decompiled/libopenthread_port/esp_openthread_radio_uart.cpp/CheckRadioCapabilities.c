/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> CheckRadioCapabilities
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   CheckRadioCapabilities(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
CheckRadioCapabilities
          (RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
           *this)

{
  otError oVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  byte abStack_14 [4];
  uint radioCaps;
  
  oVar1 = Get(this,0x120b,"i",abStack_14);
  if (oVar1 == OT_ERROR_NONE) {
    this->mRadioCaps = abStack_14[0];
    if ((abStack_14[0] & 0x6d) != 0x6d) {
      abStack_14[0] = ~abStack_14[0];
      if ((abStack_14[0] & 1) == 0) {
        pcVar3 = "";
      }
      else {
        pcVar3 = "ack-timeout ";
      }
      if ((abStack_14[0] & 4) == 0) {
        pcVar4 = "";
      }
      else {
        pcVar4 = "tx-retries ";
      }
      if ((abStack_14[0] & 8) == 0) {
        pcVar5 = "";
      }
      else {
        pcVar5 = "CSMA-backoff ";
      }
      if ((abStack_14[0] & 0x20) == 0) {
        pcVar6 = "";
      }
      else {
        pcVar6 = "tx-security ";
      }
      if ((abStack_14[0] & 0x40) == 0) {
        pcVar7 = "";
      }
      else {
        pcVar7 = "tx-timing ";
      }
      otLogCrit(0xc,_LC2,"RCP is missing required capabilities: %s%s%s%s%s",pcVar3,pcVar4,pcVar5,
                pcVar6,pcVar7);
      uVar2 = otExitCodeToString(3);
      otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","CheckRadioCapabilities",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x180,
                uVar2);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
  }
  return oVar1;
}

