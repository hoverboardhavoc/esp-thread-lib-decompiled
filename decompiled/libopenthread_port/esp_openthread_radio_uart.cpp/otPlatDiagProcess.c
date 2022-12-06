/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> otPlatDiagProcess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* otPlatDiagProcess(otInstance*, int, char**, char*, unsigned int) */

void otPlatDiagProcess(otInstance *param_1,int param_2,char **param_3,char *param_4,uint param_5)

{
  char *__s;
  int iVar1;
  int iVar2;
  char local_130 [256];
  undefined1 auStack_30 [12];
  
  __s = local_130;
  local_130[0] = '\0';
  local_130[1] = '\0';
  local_130[2] = '\0';
  local_130[3] = '\0';
  memset(local_130 + 4,0,0xfc);
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    iVar2 = snprintf(__s,(size_t)(auStack_30 + -(int)__s),"%s ");
    __s = __s + iVar2;
  }
  DAT_000160cc = param_4;
  DAT_000160d0 = param_5;
  ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
  Set(0x15920,(char *)0x3bc0);
  DAT_000160cc = (char *)0x0;
  DAT_000160d0 = 0;
  return;
}

