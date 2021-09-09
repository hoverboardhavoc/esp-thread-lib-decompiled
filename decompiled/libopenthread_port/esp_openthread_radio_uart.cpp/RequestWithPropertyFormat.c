/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  
  *(ulong *)(param_1 + 0x46c) = param_2;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
           param_1,param_3,(ulong)param_4,in_a4,&uStack_c);
  param_1[0x46c] = '\0';
  param_1[0x46d] = '\0';
  param_1[0x46e] = '\0';
  param_1[0x46f] = '\0';
  return;
}

