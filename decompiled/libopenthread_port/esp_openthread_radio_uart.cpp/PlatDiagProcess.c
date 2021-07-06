/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> PlatDiagProcess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::PlatDiagProcess(char const*, char*, unsigned int) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::PlatDiagProcess(char *param_1,char *param_2,uint param_3)

{
  undefined4 in_a3;
  
  *(uint *)(param_1 + 0x708) = param_3;
  *(undefined4 *)(param_1 + 0x70c) = in_a3;
  Set((ulong)param_1,(char *)0x3bc0);
  param_1[0x708] = '\0';
  param_1[0x709] = '\0';
  param_1[0x70a] = '\0';
  param_1[0x70b] = '\0';
  param_1[0x70c] = '\0';
  param_1[0x70d] = '\0';
  param_1[0x70e] = '\0';
  param_1[0x70f] = '\0';
  return;
}

