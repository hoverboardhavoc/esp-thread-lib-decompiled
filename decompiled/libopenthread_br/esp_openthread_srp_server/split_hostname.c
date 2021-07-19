/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> split_hostname
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void split_hostname(char *param_1,char *param_2,uint param_3)

{
  uint __n;
  char *pcVar1;
  
  pcVar1 = strchr(param_1,0x2e);
  __n = (int)pcVar1 - (int)param_1;
  if (param_3 < (uint)((int)pcVar1 - (int)param_1)) {
    __n = param_3;
  }
  strncpy(param_2,param_1,__n);
  param_2[__n] = '\0';
  return;
}

