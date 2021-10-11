/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagModeSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagModeSet(undefined1 param_1)

{
  int iVar1;
  
  DAT_000133d8 = 0;
  DAT_000133dc = 0;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x12cd0,(char *)0x3bc0);
  DAT_000133d8 = 0;
  DAT_000133dc = 0;
  if (iVar1 == 0) {
    DAT_000133d4._1_1_ = param_1;
  }
  return;
}

