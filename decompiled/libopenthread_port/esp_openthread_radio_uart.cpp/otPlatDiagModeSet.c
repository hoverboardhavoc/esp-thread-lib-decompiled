/*
 * Last changed at upstream commit 0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * https://github.com/espressif/esp-thread-lib/commit/0e7deba20b77f23c9f431ae3e05236bf6f06957d
 * Upstream date: 2022-07-05 19:22:08 +0800
 * Upstream subject: bugfix: fix timer overflow
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagModeSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagModeSet(undefined1 param_1)

{
  int iVar1;
  
  DAT_00014c34 = 0;
  DAT_00014c38 = 0;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x14488,(char *)0x3bc0);
  DAT_00014c34 = 0;
  DAT_00014c38 = 0;
  if (iVar1 == 0) {
    DAT_00014c30._2_1_ = param_1;
  }
  return;
}

