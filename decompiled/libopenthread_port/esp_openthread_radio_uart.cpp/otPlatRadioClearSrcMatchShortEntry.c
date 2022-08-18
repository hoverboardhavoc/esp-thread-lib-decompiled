/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchShortEntry(uint param_1)

{
  ushort *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Remove(0x14560,(char *)0x1304);
  if (iVar3 == 0) {
    puVar2 = &s_radio;
    for (iVar3 = 0; iVar3 < DAT_00014cae; iVar3 = iVar3 + 1) {
      puVar1 = (ushort *)(puVar2 + 0x73a);
      puVar2 = puVar2 + 2;
      if (*puVar1 == param_1) {
        *(undefined2 *)(&DAT_0001456a + (iVar3 + 0x398) * 2) =
             *(undefined2 *)(&DAT_0001456a + (DAT_00014cae + 0x397) * 2);
        DAT_00014cae = DAT_00014cae + -1;
        return;
      }
    }
  }
  return;
}

