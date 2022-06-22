/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
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
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int unaff_s3;
  undefined *unaff_s4;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  puVar6 = param_1 + 7;
  puVar7 = &uStack_28;
  do {
    *(undefined1 *)puVar7 = *puVar6;
    bVar1 = param_1 != puVar6;
    puVar6 = puVar6 + -1;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  } while (bVar1);
  iVar4 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Insert(0x14490,(char *)0x1305);
  sVar2 = DAT_00014c30;
  if (iVar4 == 0) {
    iVar3 = (int)DAT_00014c30;
    if (9 < iVar3) {
      __assert_func(0,0,0);
      goto _L0;
    }
    unaff_s4 = &DAT_00014be0;
    for (unaff_s3 = 0; unaff_s3 < iVar3; unaff_s3 = unaff_s3 + 1) {
_L0:
      iVar5 = memcmp(&uStack_28,unaff_s4,8);
      unaff_s4 = unaff_s4 + 8;
      if (iVar5 == 0) {
        return 0;
      }
    }
    (&s_radio)[(iVar3 + 0xea) * 2] = uStack_28;
    DAT_00014c30 = sVar2 + 1;
    *(undefined4 *)(&DAT_00014494 + (iVar3 + 0xea) * 8) = uStack_24;
  }
  return iVar4;
}

