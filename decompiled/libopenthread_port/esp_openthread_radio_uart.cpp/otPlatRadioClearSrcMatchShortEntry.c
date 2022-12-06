/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
          Remove(0x15920,(char *)0x1304);
  if (iVar3 == 0) {
    puVar2 = &s_radio;
    for (iVar3 = 0; iVar3 < DAT_0001606e; iVar3 = iVar3 + 1) {
      puVar1 = (ushort *)(puVar2 + 0x73a);
      puVar2 = puVar2 + 2;
      if (*puVar1 == param_1) {
        *(undefined2 *)(&DAT_0001592a + (iVar3 + 0x398) * 2) =
             *(undefined2 *)(&DAT_0001592a + (DAT_0001606e + 0x397) * 2);
        DAT_0001606e = DAT_0001606e + -1;
        return;
      }
    }
  }
  return;
}

