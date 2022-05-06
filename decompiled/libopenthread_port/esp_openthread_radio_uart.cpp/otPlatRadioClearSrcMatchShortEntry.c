/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchShortEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchShortEntry(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          Remove(0x13cc8,(char *)0x1304);
  if (iVar2 == 0) {
    puVar1 = &s_radio;
    for (iVar2 = 0; iVar2 < DAT_00014416; iVar2 = iVar2 + 1) {
      if (*(ushort *)((int)puVar1 + 0x73a) == param_1) {
        *(undefined2 *)(&DAT_00013cd2 + (iVar2 + 0x398) * 2) =
             *(undefined2 *)(&DAT_00013cd2 + (DAT_00014416 + 0x397) * 2);
        DAT_00014416 = DAT_00014416 + -1;
        return;
      }
      puVar1 = (undefined4 *)((int)puVar1 + 2);
    }
  }
  return;
}

