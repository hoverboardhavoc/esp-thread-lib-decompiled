/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  DAT_00013498 = param_4;
  DAT_0001349c = param_5;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x12d90,(char *)0x3bc0);
  DAT_00013498 = (char *)0x0;
  DAT_0001349c = 0;
  return;
}

