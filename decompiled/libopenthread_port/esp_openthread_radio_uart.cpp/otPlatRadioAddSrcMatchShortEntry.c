/*
 * Last changed at upstream commit c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * https://github.com/espressif/esp-thread-lib/commit/c5c5e57918a0eef7aae95e888df2c1a2572d6ecd
 * Upstream date: 2022-12-09 21:46:40 +0800
 * Upstream subject: lib: fix nat64 enable
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
  
  puVar2 = (undefined4 *)&DAT_00016000;
  iVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x15920,(char *)0x1304);
  if (iVar3 == 0) {
    puVar4 = &s_radio;
    iVar6 = (int)DAT_0001606e;
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

