/*
 * Last changed at upstream commit b6b61e3d4891c01e9b44cc1a27e741288192b537
 * https://github.com/espressif/esp-thread-lib/commit/b6b61e3d4891c01e9b44cc1a27e741288192b537
 * Upstream date: 2022-06-20 16:22:56 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
          Remove(0x14488,(char *)0x1305);
  sVar2 = DAT_00014c28;
  if (iVar4 == 0) {
    iVar8 = (int)DAT_00014c28;
    __s1 = &DAT_00014bd8;
    for (iVar3 = 0; iVar3 < iVar8; iVar3 = iVar3 + 1) {
      iVar5 = memcmp(__s1,auStack_28,8);
      __s1 = __s1 + 8;
      if (iVar5 == 0) {
        iVar8 = iVar8 + 0xe9;
        (&s_radio)[(iVar3 + 0xea) * 2] = (&s_radio)[iVar8 * 2];
        DAT_00014c28 = sVar2 + -1;
        *(undefined4 *)(&DAT_0001448c + (iVar3 + 0xea) * 8) =
             *(undefined4 *)(&DAT_0001448c + iVar8 * 8);
        return 0;
      }
    }
  }
  return iVar4;
}

