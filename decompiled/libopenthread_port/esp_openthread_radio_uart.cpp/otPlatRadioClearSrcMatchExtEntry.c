/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 auStack_28 [12];
  
  puVar7 = auStack_28;
  puVar8 = param_1 + 7;
  do {
    *puVar7 = *puVar8;
    bVar1 = param_1 != puVar8;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + -1;
  } while (bVar1);
  iVar5 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Remove(0x13cc8,(char *)0x1305);
  sVar2 = DAT_00014468;
  if (iVar5 == 0) {
    iVar9 = (int)DAT_00014468;
    puVar4 = &s_radio;
    for (iVar3 = 0; iVar3 < iVar9; iVar3 = iVar3 + 1) {
      iVar6 = memcmp(puVar4 + 0x1d4,auStack_28,8);
      puVar4 = puVar4 + 2;
      if (iVar6 == 0) {
        iVar9 = iVar9 + 0xe9;
        (&s_radio)[(iVar3 + 0xea) * 2] = (&s_radio)[iVar9 * 2];
        DAT_00014468 = sVar2 + -1;
        *(undefined4 *)(&DAT_00013ccc + (iVar3 + 0xea) * 8) =
             *(undefined4 *)(&DAT_00013ccc + iVar9 * 8);
        return 0;
      }
    }
  }
  return iVar5;
}

