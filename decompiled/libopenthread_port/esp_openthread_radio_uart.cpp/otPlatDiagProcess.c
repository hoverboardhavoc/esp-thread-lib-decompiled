/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagProcess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* otPlatDiagProcess(otInstance*, int, char**, char*, unsigned int) */

void otPlatDiagProcess(otInstance *param_1,int param_2,char **param_3,char *param_4,uint param_5)

{
  int iVar1;
  char *__s;
  int iVar2;
  char acStack_120 [256];
  
  __s = acStack_120;
  memset(acStack_120,0,0x100);
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    iVar2 = snprintf(__s,(size_t)(&stack0xffffffe0 + -(int)__s),"%s ");
    __s = __s + iVar2;
  }
  DAT_00014474 = param_4;
  DAT_00014478 = param_5;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x13cc8,(char *)0x3bc0);
  DAT_00014474 = (char *)0x0;
  DAT_00014478 = 0;
  return;
}

