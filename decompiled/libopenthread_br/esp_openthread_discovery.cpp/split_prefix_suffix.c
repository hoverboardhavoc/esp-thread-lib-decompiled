/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> split_prefix_suffix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* split_prefix_suffix(char const*, char*, unsigned int, char*, unsigned int) */

undefined4 split_prefix_suffix(char *param_1,char *param_2,uint param_3,char *param_4,uint param_5)

{
  uint __n;
  size_t sVar1;
  undefined4 uVar2;
  size_t __n_00;
  size_t sVar3;
  
  sVar1 = strnlen(param_1,0x100);
  if (sVar1 == 0) {
    uVar2 = 0;
  }
  else {
    __n_00 = sVar1 - 1;
    sVar3 = __n_00;
    if (param_1[__n_00] != '.') {
      __n_00 = sVar1;
      sVar3 = sVar1;
    }
    do {
      sVar1 = __n_00;
      __n_00 = sVar1 - 1;
      if ((int)__n_00 < 0) break;
    } while (param_1[__n_00] != '.');
    if ((int)__n_00 < 1) {
      strncpy(param_2,param_1,param_3);
      *param_4 = '\0';
      uVar2 = 1;
    }
    else {
      __n = (sVar3 - __n_00) - 1;
      if (__n_00 < param_3) {
        if (__n < param_5) {
          strncpy(param_2,param_1,__n_00);
          param_2[__n_00] = '\0';
          strncpy(param_4,param_1 + sVar1,__n);
          param_4[__n] = '\0';
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

