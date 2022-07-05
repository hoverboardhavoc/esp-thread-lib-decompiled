/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioAddSrcMatchShortEntry(uint param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar2 = (undefined4 *)0x14000;
  iVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x14488,(char *)0x1304);
  if (iVar3 == 0) {
    puVar4 = &s_radio;
    iVar6 = (int)DAT_00014bd6;
    iVar5 = 9;
    if (9 < iVar6) {
      iVar3 = 0;
      puVar4 = (undefined4 *)0x0;
      __assert_func(0,0);
      goto _L0;
    }
    puVar2 = &s_radio;
    for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
_L0:
      puVar1 = (ushort *)((int)puVar2 + 0x73a);
      puVar2 = (undefined4 *)((int)puVar2 + 2);
      if (*puVar1 == param_1) {
        return iVar3;
      }
    }
    *(short *)((int)puVar4 + (iVar6 + 0x398) * 2 + 10) = (short)param_1;
    *(short *)((int)puVar4 + 0x74e) = (short)iVar6 + 1;
  }
  return iVar3;
}

