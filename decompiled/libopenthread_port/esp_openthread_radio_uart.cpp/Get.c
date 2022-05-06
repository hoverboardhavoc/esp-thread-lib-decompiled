/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Get(unsigned long, char const*, ...) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::Get(ulong param_1,char *param_2,...)

{
  char *extraout_a1;
  undefined4 in_a2;
  undefined4 in_a3;
  undefined4 in_a4;
  undefined4 in_a5;
  undefined4 in_a6;
  undefined4 in_a7;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_14 = in_a3;
  uStack_10 = in_a4;
  uStack_c = in_a5;
  uStack_8 = in_a6;
  uStack_4 = in_a7;
  if (*(char *)(param_1 + 0x468) != '\0') {
    in_a2 = 0;
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  do {
    RecoverFromRcpFailure
              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                *)param_1);
    *(undefined4 **)(param_1 + 0x474) = &uStack_14;
    *(undefined4 *)(param_1 + 0x470) = in_a2;
    RequestV((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             param_1,2,(ulong)param_2,(char *)0x0,&uStack_14);
    *(undefined4 *)(param_1 + 0x470) = 0;
  } while (*(int *)(param_1 + 0x7a8) << 0x11 < 0);
  return;
}

