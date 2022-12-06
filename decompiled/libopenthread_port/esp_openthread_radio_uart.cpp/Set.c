/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Set(unsigned long, char const*, ...) */

int ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
    ::Set(ulong param_1,char *param_2,...)

{
  int iVar1;
  ulong uVar2;
  undefined1 extraout_a1;
  undefined2 uVar3;
  char *in_a2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
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
      *(undefined4 *)(param_1 + 0x478) = 6;
      iVar1 = RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        *)param_1,3,(ulong)param_2,in_a2,&uStack_14);
      *(undefined4 *)(param_1 + 0x478) = 0;
    } while ((*(uint *)(param_1 + 0x7a8) >> 0xe & 1) != 0);
    return iVar1;
  }
  uVar3 = 0;
  uVar2 = __assert_func(0,0,0);
  if ((*(byte *)(uVar2 + 0x670) & 2) == 0) {
    iVar1 = 0x1b;
  }
  else {
    *(undefined1 *)(uVar2 + 0x7a2) = extraout_a1;
    *(undefined2 *)(uVar2 + 0x7a4) = uVar3;
    *(byte *)(uVar2 + 0x7a9) = *(byte *)(uVar2 + 0x7a9) | 0x80;
    iVar1 = Set(uVar2,(char *)0x31);
    if (((iVar1 == 0) && (iVar1 = Set(uVar2,(char *)0x32), iVar1 == 0)) &&
       (iVar1 = Set(uVar2,(char *)0x30), iVar1 == 0)) {
      *(undefined1 *)(uVar2 + 0x671) = extraout_a1;
    }
  }
  return iVar1;
}

