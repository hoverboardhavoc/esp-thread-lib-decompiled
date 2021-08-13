/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_workflow_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_openthread_platform_workflow_register(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  char *__s1;
  undefined4 uVar2;
  size_t sVar3;
  char *__dest;
  int iVar4;
  char *pcVar5;
  
  sVar3 = strnlen(param_3,0x10);
  pcVar1 = s_workflow_list;
  __dest = (char *)malloc(0x1c);
  if (__dest == (char *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",
                  "esp_openthread_platform_workflow_register",0x32);
    uVar2 = 0x101;
  }
  else {
    strncpy(__dest,param_3,sVar3 & 0xff);
    *(undefined4 *)(__dest + 0x10) = param_1;
    *(undefined4 *)(__dest + 0x14) = param_2;
    __dest[0x18] = '\0';
    __dest[0x19] = '\0';
    __dest[0x1a] = '\0';
    __dest[0x1b] = '\0';
    pcVar5 = (char *)0x0;
    while (__s1 = pcVar1, __s1 != (char *)0x0) {
      iVar4 = strncmp(__s1,param_3,sVar3 & 0xff);
      if (iVar4 == 0) {
        free(__dest);
        return 0;
      }
      pcVar5 = __s1;
      pcVar1 = *(char **)(__s1 + 0x18);
    }
    if (pcVar5 == (char *)0x0) {
      uVar2 = 0;
      s_workflow_list = __dest;
    }
    else {
      *(char **)(pcVar5 + 0x18) = __dest;
      uVar2 = 0;
    }
  }
  return uVar2;
}

