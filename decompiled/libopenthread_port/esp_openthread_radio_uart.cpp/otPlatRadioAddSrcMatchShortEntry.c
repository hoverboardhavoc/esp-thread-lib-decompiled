/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioAddSrcMatchShortEntry(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x13cc8,(char *)0x1304);
  if (iVar2 == 0) {
    puVar3 = &s_radio;
    iVar5 = (int)DAT_00014416;
    if (iVar5 < 10) {
      puVar1 = &s_radio;
      for (iVar4 = 0; iVar4 < iVar5; iVar4 = iVar4 + 1) {
        if (*(ushort *)((int)puVar1 + 0x73a) == param_1) {
          return 0;
        }
        puVar1 = (undefined4 *)((int)puVar1 + 2);
      }
    }
    else {
      puVar3 = (undefined4 *)0x0;
      iVar2 = 0;
      __assert_func(0,0);
    }
    *(short *)((int)puVar3 + (iVar5 + 0x398) * 2 + 10) = (short)param_1;
    *(short *)((int)puVar3 + 0x74e) = (short)iVar5 + 1;
  }
  return iVar2;
}

