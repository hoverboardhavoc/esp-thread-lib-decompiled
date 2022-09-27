/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
  undefined4 *unaff_s4;
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
          Insert(0x14570,(char *)0x1305);
  sVar2 = DAT_00014d10;
  if (iVar4 == 0) {
    iVar3 = (int)DAT_00014d10;
    if (9 < iVar3) {
      __assert_func(0,0,0);
      goto _L0;
    }
    unaff_s4 = &DAT_00014cc0;
    for (unaff_s3 = 0; unaff_s3 < iVar3; unaff_s3 = unaff_s3 + 1) {
_L0:
      iVar5 = memcmp(&uStack_28,unaff_s4,8);
      unaff_s4 = unaff_s4 + 2;
      if (iVar5 == 0) {
        return 0;
      }
    }
    iVar3 = (iVar3 + 0xea) * 8;
    *(undefined4 *)(&s_radio + iVar3) = uStack_28;
    DAT_00014d10 = sVar2 + 1;
    *(undefined4 *)(&DAT_00014574 + iVar3) = uStack_24;
  }
  return iVar4;
}

