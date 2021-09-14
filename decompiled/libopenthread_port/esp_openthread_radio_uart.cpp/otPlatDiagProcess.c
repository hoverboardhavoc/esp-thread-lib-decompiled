/*
 * Last changed at upstream commit 48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * https://github.com/espressif/esp-thread-lib/commit/48d9b2a2ccceb75b01cf48d3ad57fabe5f17bf80
 * Upstream date: 2021-09-14 15:31:21 +0800
 * Upstream subject: OpenThread: update openthread submodule to 71bc37b(e82fe0d)
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
  DAT_000133c8 = param_4;
  DAT_000133cc = param_5;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x12cc0,(char *)0x3bc0);
  DAT_000133c8 = (char *)0x0;
  DAT_000133cc = 0;
  return;
}

