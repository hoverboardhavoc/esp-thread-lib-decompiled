/*
 * Last changed at upstream commit 8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * https://github.com/espressif/esp-thread-lib/commit/8d29f7588d91ff83ec61461e0b2dfae76d50eb0f
 * Upstream date: 2022-06-22 21:59:57 +0800
 * Upstream subject: update ot-lib
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchShortEntry(uint param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Remove(0x14490,(char *)0x1304);
  if (iVar3 == 0) {
    puVar2 = &s_radio;
    for (iVar3 = 0; iVar3 < DAT_00014bde; iVar3 = iVar3 + 1) {
      puVar1 = (ushort *)((int)puVar2 + 0x73a);
      puVar2 = (undefined4 *)((int)puVar2 + 2);
      if (*puVar1 == param_1) {
        *(undefined2 *)(&DAT_0001449a + (iVar3 + 0x398) * 2) =
             *(undefined2 *)(&DAT_0001449a + (DAT_00014bde + 0x397) * 2);
        DAT_00014bde = DAT_00014bde + -1;
        return;
      }
    }
  }
  return;
}

