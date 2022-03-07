/*
 * Last changed at upstream commit e0ff2a014fc5165513405b2e35649eb05be77ec9
 * https://github.com/espressif/esp-thread-lib/commit/e0ff2a014fc5165513405b2e35649eb05be77ec9
 * Upstream date: 2022-03-07 14:30:05 +0800
 * Upstream subject: openthread: update OpenThread submodule
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
  Insert(0x12d78,(char *)0x1305);
  return;
}

