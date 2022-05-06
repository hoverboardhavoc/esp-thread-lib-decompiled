/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  
  *(ulong *)(param_1 + 0x470) = param_2;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           param_1,param_3,(ulong)param_4,in_a4,&uStack_c);
  param_1[0x470] = '\0';
  param_1[0x471] = '\0';
  param_1[0x472] = '\0';
  param_1[0x473] = '\0';
  return;
}

