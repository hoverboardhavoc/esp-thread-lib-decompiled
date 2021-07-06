/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> RequestWithPropertyFormat
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::RequestWithPropertyFormat(char const*, unsigned long,
   unsigned long, char const*, ...) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::RequestWithPropertyFormat(char *param_1,ulong param_2,ulong param_3,char *param_4,...)

{
  char *in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  RequestWithPropertyFormatV
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             param_1,(char *)param_2,param_3,(ulong)param_4,in_a4,&uStack_c);
  return;
}

