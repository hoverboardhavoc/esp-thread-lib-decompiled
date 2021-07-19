/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> split_service_name
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void split_service_name(char *param_1,char *param_2,uint param_3,char *param_4,uint param_5,
                       char *param_6,uint param_7)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  uint __n;
  uint __n_00;
  uint __n_01;
  
  pcVar1 = strchr(param_1,0x2e);
  __n_01 = (int)pcVar1 - (int)param_1;
  if (param_3 < (uint)((int)pcVar1 - (int)param_1)) {
    __n_01 = param_3;
  }
  pcVar1 = pcVar1 + 1;
  pcVar2 = strchr(pcVar1,0x2e);
  __n_00 = (int)pcVar2 - (int)pcVar1;
  if (param_5 < (uint)((int)pcVar2 - (int)pcVar1)) {
    __n_00 = param_5;
  }
  pcVar2 = pcVar2 + 1;
  pcVar3 = strchr(pcVar2,0x2e);
  __n = (int)pcVar3 - (int)pcVar2;
  if (param_7 < (uint)((int)pcVar3 - (int)pcVar2)) {
    __n = param_7;
  }
  strncpy(param_2,param_1,__n_01);
  param_2[__n_01] = '\0';
  strncpy(param_4,pcVar1,__n_00);
  param_4[__n_00] = '\0';
  strncpy(param_6,pcVar2,__n);
  param_6[__n] = '\0';
  return;
}

