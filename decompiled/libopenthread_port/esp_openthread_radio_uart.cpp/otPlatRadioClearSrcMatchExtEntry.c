/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatRadioClearSrcMatchExtEntry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatRadioClearSrcMatchExtEntry(undefined1 *param_1)

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
  Remove(0x12cd0,(char *)0x1305);
  return;
}

