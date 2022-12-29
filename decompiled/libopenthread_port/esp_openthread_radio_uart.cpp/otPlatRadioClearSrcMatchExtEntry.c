/*
 * Last changed at upstream commit 129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * https://github.com/espressif/esp-thread-lib/commit/129ebba53c17a4b142a39d1799cb5aa0e49b231d
 * Upstream date: 2022-12-29 12:50:13 +0800
 * Upstream subject: lib: add openthread support for ESP32C6 * esp_openthread: aaa08bfe * ot-repo: 19e18753
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioClearSrcMatchExtEntry(undefined1 *param_1)

{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined *__s1;
  undefined1 auStack_28 [12];
  
  puVar6 = param_1 + 7;
  puVar7 = auStack_28;
  do {
    *puVar7 = *puVar6;
    bVar1 = param_1 != puVar6;
    puVar6 = puVar6 + -1;
    puVar7 = puVar7 + 1;
  } while (bVar1);
  iVar4 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Remove(0x159b0,(char *)0x1305);
  sVar2 = DAT_00016150;
  if (iVar4 == 0) {
    iVar8 = (int)DAT_00016150;
    __s1 = &DAT_00016100;
    for (iVar3 = 0; iVar3 < iVar8; iVar3 = iVar3 + 1) {
      iVar5 = memcmp(__s1,auStack_28,8);
      __s1 = __s1 + 8;
      if (iVar5 == 0) {
        iVar8 = (iVar8 + 0xe9) * 8;
        iVar4 = (iVar3 + 0xea) * 8;
        *(undefined4 *)(&s_radio + iVar4) = *(undefined4 *)(&s_radio + iVar8);
        DAT_00016150 = sVar2 + -1;
        *(undefined4 *)(&DAT_000159b4 + iVar4) = *(undefined4 *)(&DAT_000159b4 + iVar8);
        return 0;
      }
    }
  }
  return iVar4;
}

