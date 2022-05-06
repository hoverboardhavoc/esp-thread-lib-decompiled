/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int otPlatRadioAddSrcMatchExtEntry(undefined1 *param_1)

{
  bool bVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar3 = &uStack_28;
  puVar7 = param_1 + 7;
  do {
    *(undefined1 *)puVar3 = *puVar7;
    bVar1 = param_1 != puVar7;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar7 = puVar7 + -1;
  } while (bVar1);
  iVar5 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x13cc8,(char *)0x1305);
  sVar2 = DAT_00014468;
  if (iVar5 == 0) {
    iVar4 = (int)DAT_00014468;
    if (iVar4 < 10) {
      puVar3 = &s_radio;
      for (iVar8 = 0; iVar8 < iVar4; iVar8 = iVar8 + 1) {
        iVar6 = memcmp(&uStack_28,puVar3 + 0x1d4,8);
        puVar3 = puVar3 + 2;
        if (iVar6 == 0) {
          return 0;
        }
      }
    }
    else {
      __assert_func(0,0,0);
    }
    (&s_radio)[(iVar4 + 0xea) * 2] = uStack_28;
    DAT_00014468 = sVar2 + 1;
    *(undefined4 *)(&DAT_00013ccc + (iVar4 + 0xea) * 8) = uStack_24;
  }
  return iVar5;
}

