/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioAddSrcMatchShortEntry(uint param_1)

{
  ushort *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar2 = &DAT_00016000;
  iVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x159b0,(char *)0x1304);
  if (iVar3 == 0) {
    puVar4 = &s_radio;
    iVar6 = (int)DAT_000160fe;
    iVar5 = 9;
    if (9 < iVar6) {
      iVar3 = 0;
      puVar4 = (undefined1 *)0x0;
      __assert_func(0,0);
      goto _L0;
    }
    puVar2 = &s_radio;
    for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
_L0:
      puVar1 = (ushort *)(puVar2 + 0x73a);
      puVar2 = puVar2 + 2;
      if (*puVar1 == param_1) {
        return iVar3;
      }
    }
    *(short *)(puVar4 + (iVar6 + 0x398) * 2 + 10) = (short)param_1;
    *(short *)(puVar4 + 0x74e) = (short)iVar6 + 1;
  }
  return iVar3;
}

