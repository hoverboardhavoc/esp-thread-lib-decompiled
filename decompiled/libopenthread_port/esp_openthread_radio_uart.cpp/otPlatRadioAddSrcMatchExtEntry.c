/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioAddSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioAddSrcMatchExtEntry(undefined1 *param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 auStack_18 [20];
  
  puVar2 = auStack_18;
  puVar3 = param_1 + 7;
  do {
    *puVar2 = *puVar3;
    bVar1 = param_1 != puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + -1;
  } while (bVar1);
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Insert(0x12cc0,(char *)0x1305);
  return;
}

