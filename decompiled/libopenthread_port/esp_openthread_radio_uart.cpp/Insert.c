/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Insert
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Insert(unsigned long, char const*, ...) */

int ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::Insert(ulong param_1,char *param_2,...)

{
  ushort *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  char *in_a2;
  undefined1 *puVar5;
  undefined4 in_a3;
  undefined4 in_a4;
  int iVar6;
  undefined4 in_a5;
  int iVar7;
  undefined4 in_a6;
  undefined4 in_a7;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = in_a3;
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (*(char *)(param_1 + 0x468) == '\0') {
    do {
      RecoverFromRcpFailure
                ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)param_1);
      *(undefined4 **)(param_1 + 0x474) = &uStack_14;
      *(undefined4 *)(param_1 + 0x478) = 7;
      iVar3 = RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)param_1,4,(ulong)param_2,in_a2,&uStack_14);
      *(undefined4 *)(param_1 + 0x478) = 0;
    } while ((*(uint *)(param_1 + 0x7a8) >> 0xe & 1) != 0);
    return iVar3;
  }
  uVar4 = __assert_func(0,0,0,0);
  puVar2 = (undefined1 *)0x14000;
  iVar3 = Insert(0x14570,(char *)0x1304);
  if (iVar3 == 0) {
    puVar5 = &s_radio;
    iVar7 = (int)DAT_00014cbe;
    iVar6 = 9;
    if (9 < iVar7) {
      iVar3 = 0;
      puVar5 = (undefined1 *)0x0;
      __assert_func(0,0);
      goto _L0;
    }
    puVar2 = &s_radio;
    for (iVar6 = 0; iVar6 < iVar7; iVar6 = iVar6 + 1) {
_L0:
      puVar1 = (ushort *)(puVar2 + 0x73a);
      puVar2 = puVar2 + 2;
      if (*puVar1 == uVar4) {
        return iVar3;
      }
    }
    *(short *)(puVar5 + (iVar7 + 0x398) * 2 + 10) = (short)uVar4;
    *(short *)(puVar5 + 0x74e) = (short)iVar7 + 1;
  }
  return iVar3;
}

