/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  char *in_a2;
  undefined4 in_a3;
  undefined4 *puVar4;
  undefined4 in_a4;
  int iVar5;
  undefined4 in_a5;
  int iVar6;
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
      iVar2 = RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)param_1,4,(ulong)param_2,in_a2,&uStack_14);
      *(undefined4 *)(param_1 + 0x478) = 0;
    } while (*(int *)(param_1 + 0x7a8) << 0x11 < 0);
    return iVar2;
  }
  uVar3 = __assert_func(0,0,0,0);
  iVar2 = Insert(0x13cc8,(char *)0x1304);
  if (iVar2 == 0) {
    puVar4 = &s_radio;
    iVar6 = (int)DAT_00014416;
    if (iVar6 < 10) {
      puVar1 = &s_radio;
      for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
        if (*(ushort *)((int)puVar1 + 0x73a) == uVar3) {
          return 0;
        }
        puVar1 = (undefined4 *)((int)puVar1 + 2);
      }
    }
    else {
      puVar4 = (undefined4 *)0x0;
      iVar2 = 0;
      __assert_func(0,0);
    }
    *(short *)((int)puVar4 + (iVar6 + 0x398) * 2 + 10) = (short)uVar3;
    *(short *)((int)puVar4 + 0x74e) = (short)iVar6 + 1;
  }
  return iVar2;
}

