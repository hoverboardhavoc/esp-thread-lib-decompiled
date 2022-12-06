/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Snprintf
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Snprintf(char*, unsigned long, char const*, ...) */

char * ot::Spinel::
       RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::Snprintf
                 (char *param_1,ulong param_2,char *param_3,...)

{
  char *pcVar1;
  char *pcVar2;
  char *in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  pcVar1 = (char *)vsnprintf((char *)param_2,(size_t)param_3,in_a3,&uStack_10);
  pcVar2 = (char *)0x0;
  if ((-1 < (int)pcVar1) && (pcVar2 = param_3 + -1, pcVar1 < param_3 + -1)) {
    pcVar2 = pcVar1;
  }
  return pcVar2;
}

