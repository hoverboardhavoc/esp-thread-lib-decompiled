/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagModeSet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDiagModeSet(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    pcVar2 = "stop";
  }
  else {
    pcVar2 = "start";
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          PlatDiagProcess(s_radio,pcVar2,0);
  if (iVar1 == 0) {
    s_radio[0x705] = (undefined1)param_1;
  }
  return;
}

