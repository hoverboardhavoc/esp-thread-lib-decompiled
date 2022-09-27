/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagModeSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagModeSet(undefined1 param_1)

{
  int iVar1;
  
  DAT_00014d1c = 0;
  DAT_00014d20 = 0;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Set
                    (0x14570,(char *)0x3bc0);
  DAT_00014d1c = 0;
  DAT_00014d20 = 0;
  if (iVar1 == 0) {
    DAT_00014d18._2_1_ = param_1;
  }
  return;
}

