/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Remove(unsigned long, char const*, ...) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::Remove(ulong param_1,char *param_2,...)

{
  ushort *puVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
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
      *(undefined4 *)(param_1 + 0x478) = 8;
      RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)param_1,5,(ulong)param_2,in_a2,&uStack_14);
      *(undefined4 *)(param_1 + 0x478) = 0;
    } while ((*(uint *)(param_1 + 0x7a8) >> 0xe & 1) != 0);
    return;
  }
  uVar4 = __assert_func(0,0,0,0);
  iVar3 = Remove(0x14560,(char *)0x1304);
  if (iVar3 == 0) {
    puVar2 = &s_radio;
    for (iVar3 = 0; iVar3 < DAT_00014cae; iVar3 = iVar3 + 1) {
      puVar1 = (ushort *)(puVar2 + 0x73a);
      puVar2 = puVar2 + 2;
      if (*puVar1 == uVar4) {
        *(undefined2 *)(&DAT_0001456a + (iVar3 + 0x398) * 2) =
             *(undefined2 *)(&DAT_0001456a + (DAT_00014cae + 0x397) * 2);
        DAT_00014cae = DAT_00014cae + -1;
        return;
      }
    }
  }
  return;
}

